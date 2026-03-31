#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>

class FileHandler 
{
    public:
    static std::vector<uint8_t> getRaw(const std::string& filePath) 
    {
        std::ifstream fileStream(filePath, std::ios::binary);

        if (!fileStream.is_open()) {
            throw std::runtime_error("Cannot open file: " + filePath);
        }

        fileStream.seekg(0, std::ios::end);
        std::streamsize size = fileStream.tellg();
        fileStream.seekg(0, std::ios::beg);

        if (size < 0) {
            throw std::runtime_error("Cannot determine file size: " + filePath);
        }

        std::vector<uint8_t> output(static_cast<size_t>(size));

        if (!fileStream.read(reinterpret_cast<char*>(output.data()), size)) {
            throw std::runtime_error("Error while reading file: " + filePath);
        }

        return output;
    }
    static void writeRaw(const std::string& filePath, const std::vector<uint8_t>& data) 
    {
        std::ofstream fileStream(filePath, std::ios::binary);

        if (!fileStream.is_open()) {
            throw std::runtime_error("Cannot open file: " + filePath);
        }

        if (!fileStream.write(reinterpret_cast<const char*>(data.data()), data.size())) {
            throw std::runtime_error("Error while writing file: " + filePath);
        }
    }

};