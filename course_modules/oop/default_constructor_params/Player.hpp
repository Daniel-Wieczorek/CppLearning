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
    Player(std::string name="None", int health=0, int xp=0);
    ~Player();
};

#endif /* C793191C_C740_4DB2_BE30_F8B1259ECAA9 */
