#include <iostream>
#include <string>
#include <memory>
#include <vector>

// Token types from the lexer
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

// Lexer class (simplified for this example)
class Lexer {
private:
    std::string input;
    size_t position = 0;

public:
    Lexer(const std::string& input) : input(input) {}

    bool isEndOfFile() const {
        return position >= input.size();
    }

    Token nextToken() {
        while (position < input.size() && std::isspace(input[position])) {
            position++;
        }

        if (position >= input.size()) {
            return Token(TokenType::EndOfFile, "");
        }

        char currentChar = input[position];

        if (std::isalpha(currentChar) || currentChar == '_') {
            std::string value;
            while (position < input.size() && (std::isalnum(input[position]) || input[position] == '_')) {
                value.push_back(input[position]);
                position++;
            }
            return Token(TokenType::Identifier, value);
        }

        if (std::isdigit(currentChar)) {
            std::string value;
            while (position < input.size() && std::isdigit(input[position])) {
                value.push_back(input[position]);
                position++;
            }
            return Token(TokenType::Integer, value);
        }

        if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/') {
            position++;
            return Token(TokenType::Operator, std::string(1, currentChar));
        }

        if (currentChar == '(' || currentChar == ')') {
            position++;
            return Token(TokenType::Punctuation, std::string(1, currentChar));
        }

        return Token(TokenType::Unknown, std::string(1, currentChar));
    }
};

// Abstract Syntax Tree (AST) Node Types
class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual void print() const = 0;
};

class ExpressionNode : public ASTNode {};
class TermNode : public ASTNode {};
class FactorNode : public ASTNode {};

class BinaryOperatorNode : public ExpressionNode {
public:
    std::shared_ptr<ExpressionNode> left;
    std::shared_ptr<ExpressionNode> right;
    std::string op;

    BinaryOperatorNode(std::shared_ptr<ExpressionNode> left, std::shared_ptr<ExpressionNode> right, const std::string& op)
        : left(left), right(right), op(op) {}

    void print() const override {
        left->print();
        std::cout << " " << op << " ";
        right->print();
    }
};

class LiteralNode : public FactorNode {
public:
    std::string value;

    LiteralNode(const std::string& value) : value(value) {}

    void print() const override {
        std::cout << value;
    }
};

class IdentifierNode : public FactorNode {
public:
    std::string name;

    IdentifierNode(const std::string& name) : name(name) {}

    void print() const override {
        std::cout << name;
    }
};

// Syntax Analyzer (Parser)
class Parser {
private:
    Lexer lexer;
    Token currentToken;

    void consume() {
        currentToken = lexer.nextToken();
    }

    std::shared_ptr<ExpressionNode> parseExpression() {
        auto left = parseTerm();
        while (currentToken.type == TokenType::Operator && (currentToken.value == "+" || currentToken.value == "-")) {
            std::string op = currentToken.value;
            consume();  // Consume operator
            auto right = parseTerm();
            left = std::make_shared<BinaryOperatorNode>(left, right, op);
        }
        return left;
    }

    std::shared_ptr<ExpressionNode> parseTerm() {
        auto left = parseFactor();
        while (currentToken.type == TokenType::Operator && (currentToken.value == "*" || currentToken.value == "/")) {
            std::string op = currentToken.value;
            consume();  // Consume operator
            auto right = parseFactor();
            left = std::make_shared<BinaryOperatorNode>(left, right, op);
        }
        return left;
    }

    std::shared_ptr<FactorNode> parseFactor() {
        if (currentToken.type == TokenType::Integer) {
            std::shared_ptr<FactorNode> factor = std::make_shared<LiteralNode>(currentToken.value);
            consume();  // Consume integer
            return factor;
        } else if (currentToken.type == TokenType::Identifier) {
            std::shared_ptr<FactorNode> factor = std::make_shared<IdentifierNode>(currentToken.value);
            consume();  // Consume identifier
            return factor;
        } else if (currentToken.type == TokenType::Punctuation && currentToken.value == "(") {
            consume();  // Consume '('
            auto expr = parseExpression();
            if (currentToken.type == TokenType::Punctuation && currentToken.value == ")") {
                consume();  // Consume ')'
                return expr;
            }
            throw std::runtime_error("Expected ')'");
        }
        throw std::runtime_error("Unexpected token in factor");
    }

public:
    Parser(Lexer lexer) : lexer(lexer) {
        consume();  // Start by consuming the first token
    }

    std::shared_ptr<ExpressionNode> parse() {
        return parseExpression();
    }
};

// Main function to test the parser
int main() {
    std::string input = "a + 5 * (b - 3)";
    Lexer lexer(input);
    Parser parser(lexer);

    try {
        auto ast = parser.parse();
        std::cout << "Parse tree:\n";
        ast->print();
        std::cout << "\n";
    } catch (const std::runtime_error& e) {
        std::cerr << "Syntax error: " << e.what() << std::endl;
    }

    return 0;
}
