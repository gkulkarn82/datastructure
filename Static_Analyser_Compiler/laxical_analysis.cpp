#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <map>
#include <memory>

// Define the token types
enum class TokenType {
    Keyword,
    Identifier,
    Integer,
    Operator,
    Punctuation,
    EndOfFile,
    Unknown
};

// Token class to represent each lexeme
class Token {
public:
    TokenType type;
    std::string value;

    Token(TokenType type, const std::string& value) : type(type), value(value) {}

    void print() const {
        std::cout << "Token: " << value << " (Type: ";
        switch (type) {
            case TokenType::Keyword: std::cout << "Keyword"; break;
            case TokenType::Identifier: std::cout << "Identifier"; break;
            case TokenType::Integer: std::cout << "Integer"; break;
            case TokenType::Operator: std::cout << "Operator"; break;
            case TokenType::Punctuation: std::cout << "Punctuation"; break;
            case TokenType::EndOfFile: std::cout << "EndOfFile"; break;
            case TokenType::Unknown: std::cout << "Unknown"; break;
        }
        std::cout << ")\n";
    }
};

// Lexical Analyzer class
class Lexer {
private:
    std::string input;
    size_t position = 0;
    std::map<std::string, TokenType> keywords = {
        {"int", TokenType::Keyword},
        {"return", TokenType::Keyword}
    };

public:
    Lexer(const std::string& input) : input(input) {}

    // Helper method to check if we have reached the end of input
    bool isEndOfFile() const {
        return position >= input.size();
    }

    // Method to get the next token
    Token nextToken() {
        // Skip whitespaces
        while (position < input.size() && std::isspace(input[position])) {
            position++;
        }

        if (position >= input.size()) {
            return Token(TokenType::EndOfFile, "");
        }

        char currentChar = input[position];

        // Handle identifiers and keywords
        if (std::isalpha(currentChar) || currentChar == '_') {
            std::string value;
            while (position < input.size() && (std::isalnum(input[position]) || input[position] == '_')) {
                value.push_back(input[position]);
                position++;
            }

            // Check if it's a keyword or an identifier
            if (keywords.find(value) != keywords.end()) {
                return Token(TokenType::Keyword, value);
            } else {
                return Token(TokenType::Identifier, value);
            }
        }

        // Handle integer literals
        if (std::isdigit(currentChar)) {
            std::string value;
            while (position < input.size() && std::isdigit(input[position])) {
                value.push_back(input[position]);
                position++;
            }
            return Token(TokenType::Integer, value);
        }

        // Handle operators and punctuation
        if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '=' || 
            currentChar == ';' || currentChar == '(' || currentChar == ')') {
            std::string value(1, currentChar);
            position++;
            TokenType type = TokenType::Unknown;
            switch (currentChar) {
                case '+':
                case '-':
                case '*':
                case '=':
                    type = TokenType::Operator;
                    break;
                case ';':
                case '(':
                case ')':
                    type = TokenType::Punctuation;
                    break;
            }
            return Token(type, value);
        }

        // Unknown character
        position++;
        return Token(TokenType::Unknown, std::string(1, currentChar));
    }
};

// Main function to test the lexer
int main() {
    std::string code = "int x = 42 + 10; return x;";
    Lexer lexer(code);

    Token token = lexer.nextToken();
    while (token.type != TokenType::EndOfFile) {
        token.print();
        token = lexer.nextToken();
    }

    return 0;
}
