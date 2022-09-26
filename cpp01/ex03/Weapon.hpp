
#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{

    private:
        std::string type;
    
    public:
        Weapon();
        Weapon(std::string type);
        ~Weapon();
        void                setType(std::string type);
        const std::string& getType(void);

};

#endif