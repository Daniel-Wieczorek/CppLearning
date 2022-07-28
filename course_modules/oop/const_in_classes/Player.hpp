#ifndef C793191C_C740_4DB2_BE30_F8B1259ECAA9
#define C793191C_C740_4DB2_BE30_F8B1259ECAA9
#include <string>

class Player
{
private:
    std::string name;
    int health;
    int xp;

public:

    void set_name(std::string new_name)
    {
        name = new_name;
    }
    std::string get_name() const
    { 
        return name; 
    }

    int get_health() 
    {
        return health;
    }

    int get_xp() 
    {
        return xp;
    }

    Player(std::string name = "None", int health = 0, int xp = 0);
    
    // COPY CONSTRUCTOR
    Player(const Player &source);
    
    ~Player();
};

#endif /* C793191C_C740_4DB2_BE30_F8B1259ECAA9 */
