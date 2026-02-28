#include <iostream>
#include <string>
#include <regex>
#include <vector>
#include <chrono>
#include <utility>  // For std::pair

int main() {
    // Generate approximately 10 MB of in-memory text data
    const size_t target_size = 10 * 1024 * 1024;  // 10 MB
    std::string data;
    data.reserve(target_size);

    // Use a repeating chunk of text to fill the data
    std::string chunk = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. ";
    while (data.size() < target_size) {
        data += chunk;
    }
    data.resize(target_size);  // Ensure exact size

    // Define the regex pattern for splitting (e.g., on whitespace)

    // Start benchmark timing
    auto start = std::chrono::high_resolution_clock::now();

    // Use std::sregex_token_iterator to iterate over regions between delimiters
    std::vector<std::pair<size_t, size_t>> positions;  // Vector of {start, end} pairs (end exclusive)
    bool mode = false;
    auto curPair = std::make_pair<size_t, size_t>(0,0);
    for (size_t i = 0; i < data.size(); ++i)
    {
        if (mode) {
            if (data[i] != ' ') {
                mode = false;
                curPair.first = i;
            }
        } else {
            if (data[i] == ' ') {
                curPair.second = i - 1;
                positions.push_back(curPair);
                mode = true;
            }
        }
    }

    // End benchmark timing
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    // Output results
    std::cout << "Time taken to process 10 MB: " << duration.count() << " ms" << std::endl;
    std::cout << "Number of regions found: " << positions.size() << std::endl;

    return 0;
}
