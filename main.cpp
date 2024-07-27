#include <iostream>
#include <config.hpp>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <ctime>
#if defined(_WIN32) || defined(_WIN64)
    #define WINDOWS
    #include <windows.h>
#elif defined(__linux__) || defined(__unix) || defined(__unix__)  || defined(__APPLE__) || defined(__MACH__) || defined(__FreeBSD__)
    #define UNIX_LIKE
    #include <unistd.h>
#endif
static void version();
static void game(const std::string state);
static std::array<const std::string, 15> gameargs{"r", "-r", "rock", "-rock", "--rock",
                                                  "p", "-p", "paper", "-paper", "--paper",
                                                  "s", "-s", "scissor", "-scissor", "--scissor"};
int main(int argc, char const *argv[])
{
    #if defined(WINDOWS32) || defined(WINDOWS64)
    std::srand(GetCurrentProcessId());
    #elif defined(UNIX_LIKE)
    std::srand(getpid());
    #endif
    std::vector<std::string> cmdargs;
    switch (argc)
    {
    case 1:
        std::cout << "\"Rock Paper Scissor\"\nversion: "<<ROCKPAPERSCISSOR_VERSION<<std::endl;
        return 1;
    case 2:
        for (auto i = 0; i < argc;++i)
        cmdargs.push_back(argv[i]);
        if (std::find(cmdargs.begin(), cmdargs.end(), "--version") != cmdargs.end())
        {
            version();
            return 1;
        }
        if(std::find(gameargs.begin(), gameargs.end(), cmdargs.at(1))!= gameargs.end())
        {
            game(*std::find(gameargs.begin(), gameargs.end(), cmdargs.at(1)));
            return 1;
        }
    default:
        std::cout << "Error: Incorrect arguments!";
        return 0;
    }
}
enum class player_state : unsigned short int
{
    rock=0,paper,scissor
};
static void version()
{
    std::cout << ROCKPAPERSCISSOR_PROJECT_NAME << " - version(" << ROCKPAPERSCISSOR_VERSION << ")";
}
static std::string getStateName(const player_state &p)
{   
    switch(p)
    {
        case player_state::rock:
            return "Rock";
        case player_state::paper:
            return "Paper";
        case player_state::scissor:
            return "Scissor";
        default:
            std::cout << "Error: Checking player selected object failed!\nTerminating the program...";
            exit(0);
            break;
    }
    return "\0";
}
enum class gameState : short int
{
    undef=-2,draw,lose,win
};
static const gameState determineWinner(const player_state &p1,const player_state &p2)
{
    switch (p1)
    {
    case player_state::rock:
        switch (p2)
        {
        case player_state::rock:
            return gameState::draw;
        case player_state::paper:
           return gameState::lose;
        case player_state::scissor:
            return gameState::win;
        default:
            return gameState::undef;
        }
        break;
    case player_state::paper:
        switch (p2)
        {
        case player_state::rock:
            return gameState::win;
        case player_state::paper:
            return gameState::draw;
        case player_state::scissor:
           return gameState::lose;
        default:
           return gameState::undef;
        }
        break;
    case player_state::scissor:
        switch (p2)
        {
        case player_state::rock:
            return gameState::lose;
        case player_state::paper:
            return gameState::win;
        case player_state::scissor:
            return gameState::lose;
        default:
            return gameState::undef;
        }
        break;
    default:
        return gameState::undef;
    }
    return gameState::undef;
}
static void game(const std::string state)
{
    player_state player;
    player_state opponent = (player_state) (rand()%((2 - 0) + 1) + 0);
    if(std::find(gameargs.begin(),gameargs.begin()+5,state) != gameargs.begin()+5)
        player = player_state::rock;
    else if(std::find(gameargs.begin()+5,gameargs.begin()+10,state) != gameargs.begin()+10)
        player = player_state::paper;
    else if(std::find(gameargs.begin()+10,gameargs.end(),state) != gameargs.end())
        player = player_state::scissor;

    std::cout << "You: "+getStateName(player)+"\t\b\b"<<"Opponent: "+getStateName(opponent);

    switch (determineWinner(player,opponent))
    {
    case gameState::win:
        std::cout << "\n\t\bY O U  W I N !";
        break;
    case gameState::lose:
        std::cout << "\n\t\bY O U  L O S E !";
        break;
    case gameState::draw:
        std::cout << "\n\t\bD R A W !";
        break;
    case gameState::undef:default:
        std::cout << "Error: Unexpected situation for determinate the Winner!\nTerminating...";
        break;
    }
}