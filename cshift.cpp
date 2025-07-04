#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <unistd.h>

std::string replace(const std::string& input, char target, const std::string& replacement) {
    std::string result;
    for (char ch : input) {
        if (ch == target) {
            result += replacement;
        } else {
            result += ch;
        }
    }
    return result;
}

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    std::string cmd;
    int torun;
    int tohist;

    while (true) {
        std::cout << "usr@cshift > ";
        std::getline(std::cin, cmd);
        std::string historyCmd = "echo \"" + cmd + "\" > .cshift_hist";
        tohist = std::system(historyCmd.c_str());

        std::vector<std::string> parsed = split(cmd, ' ');

        if (parsed.empty()) {
            continue;
        }

        if (parsed[0] == "make") {
            if (parsed.size() < 3) {
                std::cout << "cshift error: insufficient arguments for make command\n";
                continue;
            }
            if (parsed[1] == "file") {
                torun = std::system(("touch " + parsed[2]).c_str());
            } else if (parsed[1] == "directory") {
                torun = std::system(("mkdir " + parsed[2]).c_str());
            } else {
                std::cout << "cshift error: invalid to-create type\n";
            }
        } else if (parsed[0] == "delete") {
            if (parsed.size() < 3) {
                std::cout << "cshift error: insufficient arguments for delete command\n";
                continue;
            }
            if (parsed[1] == "file" || parsed[1] == "directory") {
                torun = std::system(("gio trash " + parsed[2]).c_str());
            } else {
                std::cout << "cshift error: invalid to-delete type\n";
            }
            continue;
        } else if (parsed[0] == "edit") {
            if (parsed.size() < 3) {
                std::cout << "cshift error: insufficient arguments for edit command\n";
                continue;
            }
            if (parsed[1] == "--nano") {
                torun = std::system(("nano " + parsed[2]).c_str());
            } else if (parsed[1] == "--vi") {
                torun = std::system(("vi " + parsed[2]).c_str());
            } else {
                std::cout << "cshift error: invalid edit-editor\n";
            }
        } else if (parsed[0] == "execute") {
            if (parsed.size() < 2) {
                std::cout << "cshift error: insufficient arguments for execute command\n";
                continue;
            }
            std::vector<std::string> fparts = split(parsed[1], '.');
            if (fparts[1] == "js") {
                torun = std::system(("node " + parsed[1]).c_str());
            } else if (fparts[1] == "class") {
                torun = std::system(("java " + fparts[0]).c_str());
            } else {
                torun = std::system(("./" + parsed[1]).c_str());
            }
        } else if (parsed[0] == "c++") {
            if (parsed.size() < 2) {
                std::cout << "cshift error: insufficient arguments for c++ command\n";
                continue;
            }
            torun = std::system(("g++ -std=c++23 " + parsed[1]).c_str());
        } else if (parsed[0] == "c") {
            if (parsed.size() < 2) {
                std::cout << "cshift error: insufficient arguments for c command\n";
                continue;
            }
            torun = std::system(("gcc " + parsed[1]).c_str());
        } else if (parsed[0] == "move") {
            if (parsed.size() < 3) {
                std::cout << "cshift error: insufficient arguments for move command\n";
                continue;
            }
            torun = std::system(("mv " + parsed[1] + " " + parsed[2]).c_str());
        } else if (parsed[0] == "java") {
            if (parsed.size() < 2) {
                std::cout << "cshift error: insufficient arguments for java command\n";
                continue;
            }
            torun = std::system(("javac " + parsed[1]).c_str());
        } else if (parsed[0] == "js") {
            if (parsed.size() < 2) {
                std::cout << "cshift error: insufficient arguments for js command\n";
                continue;
            }
            torun = std::system(("node " + parsed[1]).c_str());
        } else if (parsed[0] == "packages") {
            if (parsed.size() < 2) {
                std::cout << "cshift error: insufficient arguments for packages command\n";
                continue;
            }
            if (parsed[1] == "all") {
                torun = std::system("sudo apt update && sudo apt install nodejs default-jdk build-essential -y");
            } else {
                torun = std::system(("sudo apt install " + parsed[1]).c_str());
            }
        } else if (parsed[0] == "end") {
            return 0;
        } else if (parsed[0] == "bash") {
            if (parsed.size() < 2) {
                std::cout << "cshift error: insufficient arguments for bash command\n";
                continue;
            }
            std::string cmd = "bash -c '";
            for (size_t i = 1; i < parsed.size(); ++i) {
                for (char c : parsed[i])
                    cmd += (c == '\'') ? "'\\''" : std::string(1, c);
                if (i != parsed.size() - 1) cmd += " ";
            }
            cmd += "'";
            torun = std::system(cmd.c_str());
        } else if (parsed[0] == "chdir") {
            if (parsed.size() < 2) {
                std::cout << "cshift error: insufficient arguments for chdir command\n";
                continue;
            }
            std::string path = parsed[1];
            if (path.contains("~")) {
                const char* home = getenv("HOME");
                if (home == nullptr) {
                    std::cout << "cshift error: HOME environment variable not set\n";
                    continue;
                }
                path = replace(path, '~', home);
            }
            torun = chdir(path.c_str());
            if (torun != 0) {
                std::perror("chdir error");
            }
        } else if (parsed[0] == "list") {
            if (parsed.size() < 2) {
                torun = std::system("ls");
            } else if (parsed[1] == "more") {
                torun = std::system("ls -alfh");
            } else {
                std::cout << "cshift error: invalid list-option";
            }
        } else {
            std::cout << "cshift error: invalid command: " << parsed[0] << "\n";
        }
    }
}
