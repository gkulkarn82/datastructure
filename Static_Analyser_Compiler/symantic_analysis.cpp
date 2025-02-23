#include <iostream>
#include <string>
#include <unordered_map>
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

// Abstract Syntax Tree (AST) Node Types
class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual void print() const = 0;
};

// Expression node for the AST
class ExpressionNode : public ASTNode {};

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

class IdentifierNode : public ExpressionNode {
public:
    std::string name;

    IdentifierNode(const std::string& name) : name(name) {}

    void print() const override {
        std::cout << name;
    }
};

class LiteralNode : public ExpressionNode {
public:
    std::string value;

    LiteralNode(const std::string& value) : value(value) {}

    void print() const override {
        std::cout << value;
    }
};

// Symbol Table to store variable types
class SymbolTable {
public:
    // Store variable names and their types
    std::unordered_map<std::string, std::string> table;

    void declare(const std::string& name, const std::string& type) {
        if (table.find(name) != table.end()) {
            std::cerr << "Error: Variable '" << name << "' already declared.\n";
        } else {
            table[name] = type;
        }
    }

    bool isDeclared(const std::string& name) const {
        return table.find(name) != table.end();
    }

    std::string getType(const std::string& name) const {
        auto it = table.find(name);
        if (it != table.end()) {
            return it->second;
        } else {
            return "";
        }
    }
};

// Parser (syntax analysis)
class Parser {
private:
    std::vector<Token> tokens;
    size_t position = 0;

public:
    Parser(const std::vector<Token>& tokens) : tokens(tokens) {}

    Token currentToken() const {
        return tokens[position];
    }

    void consume() {
        if (position < tokens.size()) {
            position++;
        }
    }

    bool isEnd() const {
        return position >= tokens.size();
    }

    std::shared_ptr<ExpressionNode> parseExpression() {
        auto left = parseTerm();
        while (currentToken().value == "+" || currentToken().value == "-") {
            std::string op = currentToken().value;
            consume();  // Consume operator
            auto right = parseTerm();
            left = std::make_shared<BinaryOperatorNode>(left, right, op);
        }
        return left;
    }

    std::shared_ptr<ExpressionNode> parseTerm() {
        auto left = parseFactor();
        while (currentToken().value == "*" || currentToken().value == "/") {
            std::string op = currentToken().value;
            consume();  // Consume operator
            auto right = parseFactor();
            left = std::make_shared<BinaryOperatorNode>(left, right, op);
        }
        return left;
    }

    std::shared_ptr<ExpressionNode> parseFactor() {
        if (currentToken().type == TokenType::Integer) {
            auto node = std::make_shared<LiteralNode>(currentToken().value);
            consume();  // Consume integer
            return node;
        } else if (currentToken().type == TokenType::Identifier) {
            auto node = std::make_shared<IdentifierNode>(currentToken().value);
            consume();  // Consume identifier
            return node;
        } else {
            // Handle error
            return nullptr;
        }
    }
};

// Semantic Analyzer
class SemanticAnalyzer {
private:
    SymbolTable symbolTable;

public:
    void analyze(std::shared_ptr<ExpressionNode> node) {
        if (auto binOpNode = dynamic_cast<BinaryOperatorNode*>(node.get())) {
            analyze(binOpNode->left);
            analyze(binOpNode->right);
        } else if (auto identifierNode = dynamic_cast<IdentifierNode*>(node.get())) {
            if (!symbolTable.isDeclared(identifierNode->name)) {
                std::cerr << "Error: Undeclared variable '" << identifierNode->name << "' used.\n";
            }
        }
    }

    void declareVariable(const std::string& name, const std::string& type) {
        symbolTable.declare(name, type);
    }
};

// Main function to test the semantic analysis
int main() {
    // Tokens for the input expression: "int x = 5 + a;"
    std::vector<Token> tokens = {
        Token(TokenType::Keyword, "int"),
        Token(TokenType::Identifier, "x"),
        Token(TokenType::Operator, "="),
        Token(TokenType::Integer, "5"),
        Token(TokenType::Operator, "+"),
        Token(TokenType::Identifier, "a"),
        Token(TokenType::Punctuation, ";"),
        Token(TokenType::EndOfFile, "")
    };

    Parser parser(tokens);

    // Semantic analysis (declaration of variable "x")
    SemanticAnalyzer semanticAnalyzer;
    semanticAnalyzer.declareVariable("x", "int");

    // Parse the expression and perform semantic checks
    std::shared_ptr<ExpressionNode> expr = parser.parseExpression();
    semanticAnalyzer.analyze(expr);  // Perform semantic analysis on the parsed expression

    return 0;
}
