#include <iostream>
#include <string>

int main()
{
    const std::string program_source =
        "#include <iostream>\n#include <string>\n\nint main() {\n\tstd::cout "
        "<< \"Hello, World!\" << std::endl;\n\treturn 0;\n}";

    std::cout << program_source << std::endl;
    return 0;
}