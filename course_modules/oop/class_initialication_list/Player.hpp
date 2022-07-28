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
    void set_name(std::string name_val);
    std::string get_name();
    Player(); // default constuctor overloaded
    Player(std::string name, int health, int xp);
    ~Player();
};

#endif /* C793191C_C740_4DB2_BE30_F8B1259ECAA9 */
