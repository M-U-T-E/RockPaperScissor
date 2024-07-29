#include <iostream>
#include <config.hpp>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <ctime>
#if defined(_WIN32) || defined(__MINGW32__) || defined(__MINGW32__)
    #define WINDOWS
    #include <windows.h>
#elif defined(__linux__) || defined(__unix) || defined(__unix__)  || defined(__APPLE__) || defined(__MACH__) || defined(__FreeBSD__)
    #define UNIX_LIKE
    #include <unistd.h>
#endif

inline static void version();
inline static void help(const int&,const std::vector<std::string>&);
static void game(const std::string);
static std::array<const std::string, 15> gameargs{"r", "-r", "rock", "-rock", "--rock",
                                                  "p", "-p", "paper", "-paper", "--paper",
                                                  "s", "-s", "scissor", "-scissor", "--scissor"};
int main(int argc, char const *argv[])
{
    #if defined(WINDOWS32) || defined(WINDOWS64) || defined(MINGW_SDK_INIT)
    std::srand(GetCurrentProcessId());
    #elif defined(UNIX_LIKE)
    std::srand(getpid());
    #endif
    static std::vector<std::string> cmdargs;
    for (auto i = 0; i < argc;++i)
        cmdargs.push_back(argv[i]);

    switch (argc)
    {
    case 1:
        std::cout << "\"Rock Paper Scissor\"\nversion: "<<ROCKPAPERSCISSOR_VERSION<<std::endl;
        return 1;
    case 2:
    
        if(cmdargs.at(1) == "-h" || cmdargs.at(1) == "--help")
        {
            help(argc,cmdargs);
            return 1;
        }
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
    case 3:
        if(cmdargs.at(2) == "-h" || cmdargs.at(2) == "--help")
            help(argc,cmdargs);
        return 1;
    default:
        std::cout << "Error: Incorrect arguments!\n";
        return 0;
    }
}
enum class player_state : unsigned short int
{
    rock=0,paper,scissor
};
inline static void version()
{
    std::cout << ROCKPAPERSCISSOR_PROJECT_NAME << " - version(" << ROCKPAPERSCISSOR_VERSION << ")\n";
}
inline static void help(const int &argc, const std::vector<std::string>&cmdargs)
{
    static std::array<const std::string, 5> helper{
        "r, -r, rock, -rock, --rock         \tselect \"rock\" for game\n",
        "p, -p, paper, -paper, --paper      \tselect \"paper\" for game\n",
        "s, -s, scissor, -scissor, --scissor\tselect \"scissor\" for game\n",
        "--help, -h                         \tdisplay this help and exit\n",
        "--version                          \toutput version information and exit\n"};
    switch(argc)
    {
    case 2:
        for(const auto &help : helper)
            std::cout << help;
        break;
    case 3:
        if(std::find(gameargs.begin(),gameargs.begin()+5,cmdargs.at(1)) != gameargs.begin()+5)
            std::cout << helper.at(0);
        else if(std::find(gameargs.begin()+5,gameargs.begin()+10,cmdargs.at(1)) != gameargs.begin()+10)
            std::cout << helper.at(1);
        else if(std::find(gameargs.begin()+10,gameargs.end(),cmdargs.at(1)) != gameargs.end())
            std::cout << helper.at(2);
        else if(cmdargs.at(1) == "-h" || cmdargs.at(1) == "--help")
            std::cout << helper.at(3);
        else if(cmdargs.at(1) == "--version")
            std::cout << helper.at(4);
        break;
    }
}
inline static std::string getStateName(const player_state &p)
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
            std::cout << "Error: Checking player selected object failed!\nTerminating the program...\n";
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
        std::cout << "\n\t\bY O U  W I N !\n";
        break;
    case gameState::lose:
        std::cout << "\n\t\bY O U  L O S E !\n";
        break;
    case gameState::draw:
        std::cout << "\n\t\bD R A W !\n";
        break;
    case gameState::undef:default:
        std::cout << "Error: Unexpected situation for determinate the Winner!\nTerminating...\n";
        break;
    }
}