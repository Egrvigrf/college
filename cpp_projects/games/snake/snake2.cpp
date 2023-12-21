#include <iostream>
#include <random>
#include <cstring>
#include <conio.h> //isn't stl
#include <chrono>  //sleep
#include <thread>
using namespace std;
struct link_snk
{
    int x, y;
    link_snk *next = NULL;
};
class snk
{
public:
    int speed;
    int len;
    char dir;
    link_snk *head;
    char snk_head_image;
    char snk_body_image;
    snk()
    {
        speed = 150;
        len = 2;
        dir = 'w';
        snk_head_image = '@';
        snk_body_image = '*';
    }
    void premove(snk *, int &, int &);
    void move(snk *, int, int);
    bool is_crash(link_snk *,int,int);
    void eat(snk *, int, int);
};
int rows = 30;
int cols = 30;
int fruit_x, fruit_y;
bool food_is_exist = true;
snk snake;
snk *const snake_p = &snake;
bool fruit_is_exist = true;
void moveCursorTo(int y, int x);
void fruit_generate();
void game_init();
void game_over();
int main()
{
    game_init();
    while (true)
    {
        if (fruit_is_exist == false)
        {
            fruit_generate();
        }
        int h_x, h_y;//future coordinates of new head
        snake.premove(snake_p, h_x, h_y);
        if (snake.is_crash(snake_p->head,h_x,h_y))
        {
            break;
        }
        else if (fruit_x == h_x and fruit_y == h_y)
        {
            snake.eat(snake_p, h_x, h_y);
        }
        else
        {
            snake.move(snake_p, h_x, h_y);
        }
        chrono::milliseconds pauseTime(snake.speed);
        this_thread::sleep_for(pauseTime);
    }
    game_over();
    return 0;
}
void snk::premove(snk *snake_p, int &newhead_x, int &newhead_y)
{
    char dir = snake_p->dir;
    if (kbhit())
    {
        dir = getch();//avoid direction collision
        if (dir == 'a' || dir == 's' || dir == 'd' || dir == 'w')
        {
            if(dir == 'w' and snake_p->dir == 's')
                dir = 's';
            else if (dir == 's' and snake_p->dir == 'w')
                dir = 'w';
            else if (dir == 'a' and snake_p->dir == 'd')
                dir = 'd';
            else if (dir == 'd' and snake_p->dir == 'a')
                dir = 'a';
            snake_p->dir = dir;
        }
    }
    switch (snake_p->dir)
    {
    case 'w':
        newhead_x = (snake_p->head)->x - 1;
        newhead_y = (snake_p->head)->y;
        break;
    case 's':
        newhead_x = (snake_p->head)->x + 1;
        newhead_y = (snake_p->head)->y;
        break;
    case 'a':
        newhead_x = (snake_p->head)->x;
        newhead_y = (snake_p->head)->y - 1;
        break;
    case 'd':
        newhead_x = (snake_p->head)->x;
        newhead_y = (snake_p->head)->y + 1;
    }
}
void snk::move(snk *snake_p, int new_x, int new_y)
{
    link_snk *p = snake_p->head;
    while ((p->next)->next != NULL)
    {
        p = p->next;
    }
    moveCursorTo((p->next)->x, (p->next)->y);
    cout << " ";
    delete p->next;
    p->next = NULL;   // delete tail
    p = new link_snk; // change head
    p->next = snake_p->head;
    p->x = new_x;
    p->y = new_y;
    moveCursorTo(new_x, new_y);
    cout << snake_p->snk_head_image;
    moveCursorTo(snake_p->head->x, snake_p->head->y);
    cout << snake_p->snk_body_image; // head image -> body image
    snake_p->head = p;
}
bool snk::is_crash(link_snk * p, int x, int y)
{
    if((x == 1) || (x == rows)|| (y == 1 )|| (y == cols))
    {
        return true;
    }
    while (p->next != NULL)
    {
        if ((x == p->x) & (y == p->y))
        {
            return true;
        }
        p = p->next;
    }
    if ((x == p->x) & (y == p->y))
    {
        return true;
    }
    return false;
}
void snk::eat(snk *snake_p, int new_x, int new_y)
{
    moveCursorTo(snake_p->head->x, snake_p->head->y);
    cout << snk_body_image;
    link_snk *p = new link_snk;
    p->x = new_x;
    p->y = new_y;
    p->next = snake_p->head;
    snake_p->head = p;
    moveCursorTo(new_x, new_y);
    cout << snk_head_image;
    snake_p->len++;
    fruit_is_exist = false;
}
void fruit_generate()
{
    do
    {
        fruit_x = rand() % (rows - 1)+2;
        fruit_y = rand() % (cols - 1)+2;
    } while (snake.is_crash(snake_p->head, fruit_x, fruit_y));
    moveCursorTo(fruit_x, fruit_y);
    cout << '.';
    fruit_is_exist = true;
}
void moveCursorTo(int y, int x)
{
    cout << "\033[" << y << ";" << x << "H";
}
void game_init()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    rows -= rand() % 10;
    cols += rand() % 10;
    cout << "\e[?25l";
    moveCursorTo(1, 1);
    cout << string(cols, '#') << endl;//draw walls
    for (int i = 2; i <= rows-1; i++)
    {
        moveCursorTo(i, 1);
        cout << "#";
        moveCursorTo(i, cols);
        cout << "#";
    }
    moveCursorTo(rows, 1);
    cout << string(cols, '#');
    snake.head = new link_snk; //initailize snake
    snake.head->x = rand() % (rows - 10) + 8;
    snake.head->y = rand() % (cols - 10) + 8;
    moveCursorTo(snake.head->x, snake.head->y);
    cout << snake.snk_head_image;
    link_snk *tail = new link_snk;
    tail->x = snake.head->x+1;
    tail->y = snake.head->y;
    snake.head->next = tail;
    moveCursorTo(tail->x, tail->y);
    cout << snake.snk_body_image;
    fruit_generate(); // initailize fruit
}
void game_over()
{
    cout << "\x1b[2J";
    moveCursorTo(1, 1);
    cout << "Game over" << endl;
    cout << "length:" << snake.len;
}