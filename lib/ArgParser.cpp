#include "ArgParser.h"

bool ArgumentParser::ArgParser::Parse(std::vector<std::string> argv) {
    size_t argc = argv.size();
    std::string option;
    for (size_t i = 1; i < argc; i++) {
        option = argv[i];
        if (option == "-h" || option == "--help") {
            HelpDescription();
            return true;
        }
        if (option[0] != '-') {
            if (variables == nullptr) {
                return false;
            }
            else {
                int x = atoi(option.c_str());
                variables->store_->push_back(x);
                variables->used = true;
            }
        }
        else {
            if (option[1] == '-') {
                size_t id_eq = -1;
                int cnt = 0;
                for (size_t j = 2; j < option.size(); j++) {
                    if (option[j] == '=') {
                        id_eq = j;
                        cnt++;
                    }
                }
                if (cnt < 1) {
                    std::string param_name = option.erase(0, 2);
                    for (size_t j = 0; j < bool_arguments.size(); j++) {
                        if (bool_arguments[j].param_long_ == param_name) {
                            bool_arguments[j].param_value_ = true;
                            bool_arguments[j].used = true;
                            break;
                        }
                    }
                }
                if (cnt == 1) {
                    std::string param_name = option.substr(2, id_eq - 2);
                    std::string value = option.substr(id_eq + 1, option.size() - (id_eq + 1));
                    for (size_t j = 0; j < int_arguments.size(); j++) {
                        if (int_arguments[j].param_long_ == param_name) {
                            if (!int_arguments[j].is_store_) {
                                int_arguments[j].param_value_ = atoi(value.c_str());
                                int_arguments[j].used = true;
                            }
                            else {
                                int_arguments[j].store_->push_back(atoi(value.c_str()));
                                int_arguments[j].used = true;
                            }
                            break;
                        }
                    }
                    for (size_t j = 0; j < string_arguments.size(); j++) {
                        if (string_arguments[j].param_long_ == param_name) {
                            if (!string_arguments[j].is_store_) {
                                string_arguments[j].param_value_ = value;
                                string_arguments[j].used = true;
                            }
                            else {
                                *string_arguments[j].store_ += value;
                                string_arguments[j].used = true;
                            }
                            break;
                        }
                    }
                }
            }
            else {
                size_t id_eq = -1;
                for (size_t j = 1; j < option.size(); j++) {
                    if (option[j] == '=') {
                        id_eq = j;
                    }
                }
                if (id_eq == -1) {
                    for (size_t j = 1; j < option.size(); j++) {
                        char param_short = option[j];
                        for (size_t k = 0; k < bool_arguments.size(); k++) {
                            if (param_short == bool_arguments[k].param_short_) {
                                bool_arguments[k].used = true;
                                bool_arguments[k].param_value_ = true;
                            }
                        }
                    }
                }
                else {
                    char param_name = option[1];
                    std::string value = option.substr(3, option.size() - 3);
                    for (size_t j = 0; j < int_arguments.size(); j++) {
                        if (int_arguments[j].param_short_ == param_name) {
                            int_arguments[j].param_value_ = atoi(value.c_str());
                            int_arguments[j].used = true;
                            break;
                        }
                    }
                    for (size_t j = 0; j < string_arguments.size(); j++) {
                        if (string_arguments[j].param_short_ == param_name) {
                            string_arguments[j].param_value_ = value;
                            string_arguments[j].used = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    for (size_t i = 0; i < int_arguments.size(); i++) {
        if (!int_arguments[i].used) {
            return false;
        }
        if (int_arguments[i].is_store_) {
            if (int_arguments[i].store_->size() < int_arguments[i].store_size_) {
                return false;
            }
        }
    }
    for (size_t i = 0; i < string_arguments.size(); i++) {
        if (!string_arguments[i].used) {
            return false;
        }
    }
    for (size_t i = 0; i < bool_arguments.size(); i++) {
        if (!bool_arguments[i].used) {
            return false;
        }
    }
    return true;
}

bool ArgumentParser::ArgParser::Parse(int argc, char** argv) {
    std::string option;
    for (size_t i = 1; i < argc; i++) {
        option = argv[i];
        if (option == "-h" || option == "--help") {
            HelpDescription();
            return true;
        }
        if (option[0] != '-') {
            if (variables == nullptr) {
                return false;
            }
            else {
                int x = atoi(option.c_str());
                variables->variables_.push_back(x);
            }
        }
        else {
            if (option[1] == '-') {
                size_t id_eq = -1;
                int cnt = 0;
                for (size_t j = 2; j < option.size(); j++) {
                    if (option[j] == '=') {
                        id_eq = j;
                        cnt++;
                    }
                }
                if (cnt < 1) {
                    std::string param_name = option.erase(0, 2);
                    for (size_t j = 0; j < bool_arguments.size(); j++) {
                        if (bool_arguments[j].param_long_ == param_name) {
                            bool_arguments[j].param_value_ = true;
                            bool_arguments[j].used = true;
                            break;
                        }
                    }
                }
                if (cnt == 1) {
                    std::string param_name = option.substr(2, id_eq - 2);
                    std::string value = option.substr(id_eq + 1, option.size() - (id_eq + 1));
                    for (size_t j = 0; j < int_arguments.size(); j++) {
                        if (int_arguments[j].param_long_ == param_name) {
                            if (!int_arguments[j].is_store_) {
                                int_arguments[j].param_value_ = atoi(value.c_str());
                                int_arguments[j].used = true;
                            }
                            else {
                                int_arguments[j].store_->push_back(atoi(value.c_str()));
                                int_arguments[j].used = true;
                            }
                            break;
                        }
                    }
                    for (size_t j = 0; j < string_arguments.size(); j++) {
                        if (string_arguments[j].param_long_ == param_name) {
                            if (!string_arguments[j].is_store_) {
                                string_arguments[j].param_value_ = value;
                                string_arguments[j].used = true;
                            }
                            else {
                                *string_arguments[j].store_ += value;
                                string_arguments[j].used = true;
                            }
                            break;
                        }
                    }
                }
            }
            else {
                size_t id_eq = -1;
                for (size_t j = 1; j < option.size(); j++) {
                    if (option[j] == '=') {
                        id_eq = j;
                    }
                }
                if (id_eq == -1) {
                    for (size_t j = 1; j < option.size(); j++) {
                        char param_short = option[j];
                        for (size_t k = 0; k < bool_arguments.size(); k++) {
                            if (param_short == bool_arguments[k].param_short_) {
                                bool_arguments[k].used = true;
                                bool_arguments[k].param_value_ = true;
                            }
                        }
                    }
                }
                else {
                    char param_name = option[1];
                    std::string value = option.substr(3, option.size() - 3);
                    for (size_t j = 0; j < int_arguments.size(); j++) {
                        if (int_arguments[j].param_short_ == param_name) {
                            int_arguments[j].param_value_ = atoi(value.c_str());
                            int_arguments[j].used = true;
                            break;
                        }
                    }
                    for (size_t j = 0; j < string_arguments.size(); j++) {
                        if (string_arguments[j].param_short_ == param_name) {
                            string_arguments[j].param_value_ = value;
                            string_arguments[j].used = true;
                            break;
                        }
                    }
                }
            }
        }
    }
    for (size_t i = 0; i < int_arguments.size(); i++) {
        if (!int_arguments[i].used) {
            return false;
        }
    }
    for (size_t i = 0; i < string_arguments.size(); i++) {
        if (!string_arguments[i].used) {
            return false;
        }
    }
    for (size_t i = 0; i < bool_arguments.size(); i++) {
        if (!bool_arguments[i].used) {
            return false;
        }
    }
    return true;
}

ArgumentParser::ArgParser&
ArgumentParser::ArgParser::AddStringArgument(const std::string& param_long, const std::string& description) {
    string_arguments.emplace_back(param_long, description);
    Last_Arg("string");
    return *this;
}

ArgumentParser::ArgParser&
ArgumentParser::ArgParser::AddStringArgument(char param_short, const std::string& param_long, const std::string& description) {
    string_arguments.emplace_back(param_short, param_long, description);
    Last_Arg("string");
    return *this;
}

ArgumentParser::ArgParser&
ArgumentParser::ArgParser::AddIntArgument(const std::string& param_long) {
    int_arguments.emplace_back(param_long);
    Last_Arg("int");
    return *this;
}

ArgumentParser::ArgParser&
ArgumentParser::ArgParser::AddIntArgument(char param_short, const std::string& param_long) {
    int_arguments.emplace_back(param_short, param_long);
    Last_Arg("int");
    return *this;
}

ArgumentParser::ArgParser&
ArgumentParser::ArgParser::AddIntArgument(const std::string& param_long, const std::string& description) {
    int_arguments.emplace_back(param_long, description);
    Last_Arg("int");
    return *this;
}

ArgumentParser::ArgParser
& ArgumentParser::ArgParser::AddFlag(char param_short, const std::string& param_long) {
    bool_arguments.emplace_back(param_short, param_long);
    bool_arguments.back().param_value_ = true;
    Last_Arg("bool");
    return *this;
}

ArgumentParser::ArgParser
& ArgumentParser::ArgParser::AddFlag(char param_short, const std::string& param_long, const std::string& description) {
    bool_arguments.emplace_back(param_short, param_long, description);
    bool_arguments.back().param_value_ = true;
    Last_Arg("bool");
    return *this;
}

ArgumentParser::ArgParser
& ArgumentParser::ArgParser::AddFlag(const std::string& param_long, const std::string& description) {
    bool_arguments.emplace_back(param_long, description);
    bool_arguments.back().param_value_ = true;
    Last_Arg("bool");
    return *this;
}

std::string
ArgumentParser::ArgParser::GetStringValue(const std::string& s) {
    for (size_t i = 0; i < string_arguments.size(); i++) {
        if (string_arguments[i].param_long_ == s) {
            return (string_arguments[i].param_value_);
        }
    }
}

int ArgumentParser::ArgParser::GetIntValue(const std::string& s) {
    for (size_t i = 0; i < this->int_arguments.size(); i++) {
        if (int_arguments[i].param_long_ == s) {
            return (int_arguments[i].param_value_);
        }
    }
}

int ArgumentParser::ArgParser::GetIntValue(const std::string& param_long, int id) {
    for (size_t i = 0; i < this->int_arguments.size(); i++) {
        if (int_arguments[i].param_long_ == param_long) {
            std::vector<int>tmp = *int_arguments[i].store_;
            return tmp[id];
        }
    }
}

bool ArgumentParser::ArgParser::GetFlag(const std::string& param_long) {
    for (size_t i = 0; i < this->bool_arguments.size(); i++) {
        if (bool_arguments[i].param_long_ == param_long) {
            return bool_arguments[i].param_value_;
        }
    }
}

ArgumentParser::ArgParser&
ArgumentParser::ArgParser::Default(std::variant<std::string, bool> value) {
    if(std::holds_alternative<std::string>(value)){
        string_arguments.back()->param_value_ = (std::get<std::string>(value));
        string_arguments.back()->used = true;
    }
    else {
        bool_arguments.back()->param_value_ = (std::get<bool>(value));
        bool_arguments.back()->used = true;
    }
    return *this;
}

ArgumentParser::ArgParser&
ArgumentParser::ArgParser::StoreValue(std::string& value) {
    string_arguments.back()->is_store_ = true;
    string_arguments.back()->store_ = &value;
    return *this;
}

ArgumentParser::ArgParser
& ArgumentParser::ArgParser::StoreValue(bool& value) {
    bool_arguments.back()->is_store_ = true;
    bool_arguments.back()->store_ = value;
    return *this;
}

ArgumentParser::ArgParser& ArgumentParser::ArgParser::StoreValues(std::vector<int>& values) {
    int_arguments.back()->is_store_ = true;
    int_arguments.back()->store_ = &values;
    return *this;
}

void ArgumentParser::ArgParser::Last_Arg(const std::string& last_type) {
    last_argumet_type = last_type;
}

ArgumentParser::ArgParser& ArgumentParser::ArgParser::MultiValue(size_t size) {
    if (this->last_argumet_type == "int") {
        int_arguments.back()->store_size_ = size;
        int_arguments.back()->is_store_ = true;
    }
    else {
        string_arguments.back()->store_size_ = size;
        string_arguments.back()->is_store_ = true;
    }
    return *this;
}

ArgumentParser::ArgParser& ArgumentParser::ArgParser::Positional() {
    variables = int_arguments.back();
    return *this;
}

void ArgumentParser::ArgParser::AddHelp(char param_short, const std::string& param_long, const std::string& description) {
    help_short = param_short;
    help_long = param_long;
    help_description = description;
}

bool ArgumentParser::ArgParser::Help() {
    return true;
}

std::string ArgumentParser::ArgParser::HelpDescription() {
    std::string help = "";
    help += name + "\n";
    help += help_description + "\n" + "\n";
    for (size_t i = 0; i < string_arguments.size(); i++) {
        if (string_arguments[i]->param_short_ != ' ') {
            help += "-";
            help += (string_arguments[i]->param_short_);
            help += ",  ";
        } else {
            help += "     ";
        }
        help += "--";
        help += string_arguments[i]->param_long_;
        help += "=<string>,  ";
        help += string_arguments[i]->description_;
        if (string_arguments[i]->is_store_) {
            help += " [repeated, min args = ";
            help += std::to_string(string_arguments[i]->store_size_);
            help += "]";
        }
        if (string_arguments[i]->def) {
            help += " [default = ";
            help += string_arguments[i]->param_value_;
            help += "]";
        }
        help += "\n";
    }
    for (size_t i = 0; i < bool_arguments.size(); i++) {
        if (bool_arguments[i]->param_short_ != ' ') {
            help += "-";
            help += (bool_arguments[i]->param_short_);
            help += ",  ";
        } else {
            help += "     ";
        }
        help += "--";
        help += bool_arguments[i]->param_long_;
        help += ",  " + bool_arguments[i]->description_;
        if (bool_arguments[i]->def) {
            help += " [default = ";
            help += (bool_arguments[i]->param_value_ ? "true" : "false");
            help += ']';
        }
        help += "\n";
    }
    for (size_t i = 0; i < int_arguments.size(); i++) {
        if (int_arguments[i]->param_short_ != ' ') {
            help += "-";
            help += (int_arguments[i]->param_short_);
            help += ",  ";
        } else {
            help += "    ";
        }
        help += "--";
        help += int_arguments[i]->param_long_;
        help += "=<int>,  ";
        help += int_arguments[i]->description_;
        if (int_arguments[i]->is_store_) {
            help += " [repeated, min args = ";
            help += std::to_string(int_arguments[i]->store_size_);
            help += "]";
        }
        if (int_arguments[i]->def) {
            help += " [default = ";
            help += std::to_string(int_arguments[i]->param_value_);
            help += "]";
        }
        help += "\n";
    }
    help += "\n";
    help += "-h, --help Display this help and exit\n";
    return help;
}
