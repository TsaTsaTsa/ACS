#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
#include <fstream>

std::queue<std::pair<std::string, int>> parts;
std::mutex parts_mutex;
std::mutex encodedText_mutex;
std::vector<std::string> encoded_text;
const int part_len = 5;

void hashText() {
    while (true) {
        std::string text;
        std::string encoded;
        int index;

        {
            const std::lock_guard<std::mutex> lock(parts_mutex);
            if (!parts.empty()) {
                text = parts.front().first;
                parts.pop();

                index = parts.front().second;
            } else {
                return;
            }
        }

        for (char c: text) {
            if (c == '\n') {
                encoded += '\n';
            } else if (c == '\r') {
                continue;
            } else {
                encoded += std::to_string((int) c) + " ";
            }
        }

        {
            const std::lock_guard<std::mutex> lock(encodedText_mutex);
            encoded_text[index / part_len] = encoded;
        }
    }
}

void createThreads() {
    std::vector<std::thread> threads;
    threads.reserve(10);

    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(&hashText);
    }

    for (int i = 0; i < 10; ++i) {
        threads[i].join();
    }
}

std::string readFileIntoString(const std::string &path) {
    std::cout << "===== START =====" << '\n';

    std::ifstream input_file(path);
    if (!input_file.is_open()) {
        std::cout << "Could not open the file - '"
                  << path << "'" << std::endl;
        exit(EXIT_FAILURE);
    }
    return std::string((std::istreambuf_iterator<char>(input_file)), std::istreambuf_iterator<char>());
}

void parseText(std::string &text) {
    for (int i = 0; i < text.size(); i += part_len) {
        parts.push(std::make_pair(text.substr(i, part_len), i));
    }
}

void writeAnswer(std::string out_path) {
    std::ofstream output(out_path);
    output << "===== ENCODED TEXT =====" << '\n';

    for (int i = 0; i < encoded_text.size(); i++) {
        output << encoded_text[i];
    }

    std::cout << "===== END =====" << '\n';
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cout << "Incorrect qualifier value!" << std::endl
                  << "  Waited:" << std::endl
                  << "    command infile outfile" << std::endl;

        return 1;
    }
    std::string text = readFileIntoString(argv[1]);
    parseText(text);

    encoded_text.resize(parts.size());

    std::cout << "===== ENCODED =====" << '\n';
    createThreads();

    writeAnswer(argv[2]);

    return 0;
}
