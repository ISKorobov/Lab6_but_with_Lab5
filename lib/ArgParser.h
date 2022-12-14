#pragma once

#include <vector>
#include <string>
#include <variant>

struct BoolArgument {
    bool used = false;
    std::string param_long_;
    char param_short_;
    bool param_value_;
    std::string description_;

    bool is_store_ = false;
    bool store_;

    BoolArgument(char param_short, const std::string& param_long) {
        param_short_ = param_short;
        param_long_ = param_long;
    }

    BoolArgument(char param_short, const std::string& param_long, const std::string& description) {
        param_short_ = param_short;
        param_long_ = param_long;
        description_ = description;
    }

    BoolArgument(const std::string& param_long, const std::string& description) {
        param_short_ = ' ';
        param_long_ = param_long;
        description_ = description;
    }
};

struct IntArgument {
    bool used = false;

    std::string param_long_;
    char param_short_;
    int param_value_;
    std::vector<int> param_values_;

    std::string description_;

    bool flag_variables_ = false;
    std::vector<int> variables_;

    size_t store_size_;
    bool is_store_ = false;
    std::vector<int>* store_ = nullptr;

    IntArgument(const std::string& param_long) {
        param_short_ = ' ';
        param_long_ = param_long;
    }

    IntArgument(char param_short, const std::string& param_long) {
        param_long_ = param_long;
        param_short_ = param_short;
    }

    IntArgument(const std::string& param_long, const std::string& description) {
        param_short_ = ' ';
        param_long_ = param_long;
        description_ = description;
    }
};

struct StringArgument {
    bool used = false;

    char param_short_;
    std::string param_long_;
    std::string param_value_;
    std::string* store_ = nullptr;

    std::string description_;

    bool is_store_ = false;
    size_t store_size_;

    StringArgument(const std::string& param_long, const std::string& description = "") {
        param_short_ = ' ';
        param_long_ = param_long;
        description_ = description;
    }

    StringArgument(char param_short, const std::string& param_long, const std::string& description = "") {
        param_long_ = param_long;
        param_short_ = param_short;
        description_ = description;
    }
};

namespace ArgumentParser {

    class ArgParser {
    private:
        std::string name;

        std::vector<IntArgument> int_arguments;
        std::vector<BoolArgument> bool_arguments;
        std::vector<StringArgument> string_arguments;

        std::string store_value_string_param;
        std::string* store_value_string_value = nullptr;

        std::string store_value_int_param;
        std::vector<int>* store_value_int_value = nullptr;

        std::string store_value_bool_param; // åñëè âñòðåòèì òàêîé ïàðàì
        bool* store_value_bool_value = nullptr; // òî çíà÷åíèå ñîõðàíèì âîò ñþäà

        std::string last_argumet_type;

        char help_short;
        std::string help_long;
        std::string help_description;

    public:
        IntArgument* variables;

        ArgParser(const std::string& s) {
            name = s;
        }

        void Last_Arg(const std::string& basicString);

        bool Parse(std::vector<std::string> argv);

        bool Parse(int argc, char** argv);

        ArgParser& Default(std::variant<std::string, bool> value);

        ArgParser& StoreValue(std::string& value);

        ArgParser& StoreValue(bool& value);

        std::string GetStringValue(const std::string& s);

        ArgParser& AddStringArgument(const std::string& param_long, const std::string& description = "");

        ArgParser& AddStringArgument(char param_short, const std::string& param_long, const std::string& description = "");

        ArgParser& AddIntArgument(const std::string& param_long);

        ArgParser& AddIntArgument(char param_short, const std::string& param_long);

        ArgParser& AddIntArgument(const std::string& param_long, const std::string& description);

        ArgParser& AddFlag(char param_short, const std::string& param_long);

        ArgParser& AddFlag(char param_short, const std::string& param_long, const std::string& description);

        ArgParser& AddFlag(const std::string& param_long, const std::string& description);

        int GetIntValue(const std::string& param_long);

        int GetIntValue(const std::string& param_long, int id);

        bool GetFlag(const std::string& param_long);

        ArgParser& Positional();

        ArgParser& MultiValue(size_t size = 0);

        ArgParser& StoreValues(std::vector<int>& values);

        void AddHelp(char param_short, const std::string& param_long, const std::string& description);

        bool Help();

        std::string HelpDescription();
    };

} // namespace ArgumentParser
