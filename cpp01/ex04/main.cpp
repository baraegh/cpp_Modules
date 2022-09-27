
#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    size_t pos;
    std::string line;
    std::string s1, s2, file;

    if (ac == 4)
    {
        file = av[1];
        s1 = av[2];
        s2 = av[3];
    
        std::ifstream   ifs(file);
        if (!ifs)
        {
            std::cerr << "failed to open file " << file << std::endl;
            return 1;
        }
        std::ofstream   ofs(file + ".replace");

        if (!ofs)
        {
            std::cerr << "failed to create file " << file + ".replace" << std::endl;
            return 1;
        }

        while (std::getline(ifs, line))
        {
            pos = 0;
            while ((pos = line.find(s1, pos)) != std::string::npos)
            {
                line.erase(pos, s1.size());
                line = line.substr(0, pos) + s2 + line.substr(pos, line.size());
                pos += s2.size();
            }
            ofs << line + "\n";
            line.clear();
        }

        ifs.close();
        ofs.close();
    }
    else
        std::cout << "wrong number of args!\n";
    return 0;
}