#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

static std::string replaceAll(const std::string& text,
                              const std::string& s1,
                              const std::string& s2)
{
    if (s1.empty()) return text; // evitar bucle infinito
    std::string out;
    std::string::size_type pos = 0;
    while (true) {
        std::string::size_type i = text.find(s1, pos);
        if (i == std::string::npos) {
            out.append(text, pos, std::string::npos);
            break;
        }
        out.append(text, pos, i - pos); // lo que hay antes de s1
        out.append(s2);                 // sustitución
        pos = i + s1.size();            // avanzar tras s1
    }
    return out;
}

int main(int argc, char** argv)
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
        return 1;
    }
    const std::string filename = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];

    if (s1.empty()) {
        std::cerr << "Error: s1 must not be empty\n";
        return 1;
    }

    std::ifstream in(filename.c_str(), std::ios::in | std::ios::binary);
    if (!in) {
        std::cerr << "Error: cannot open input file: " << filename << "\n";
        return 1;
    }

    std::ostringstream oss;
    oss << in.rdbuf();            // read everything
    std::string content = oss.str();
    in.close();

    std::string replaced = replaceAll(content, s1, s2);

    std::ofstream out((filename + ".replace").c_str(),
                      std::ios::out | std::ios::binary | std::ios::trunc);
    if (!out) {
        std::cerr << "Error: cannot create output file\n";
        return 1;
    }
    out << replaced;
    if (!out) {
        std::cerr << "Error: write failed\n";
        return 1;
    }
    out.close();
    return 0;
}
