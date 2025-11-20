//Command

#include <iostream>
#include <stack>
#include <string>
#include <memory>

struct ICommand
{
    virtual ~ICommand() = default;
    virtual void execute() = 0;
    virtual void undo() = 0;
};

// Receiver
class TextDocument
{
public:
    void insert(const std::string& text) {
        content_ += text;
    }

    void erase(size_t count) {
        if (count <= content_.size())
            content_.erase(content_.size() - count);
    }

    void show() const {
        std::cout << "Content: " << content_ << "\n";
    }

private:
    std::string content_;
};

// come commands
class InsertCommand : public ICommand
{
public:
    InsertCommand(TextDocument& doc, std::string text)
        : doc_(doc), text_(std::move(text)) {}

    void execute() override {
        doc_.insert(text_);
    }

    void undo() override {
        doc_.erase(text_.size());
    }

private:
    TextDocument& doc_;
    std::string text_;
};

// Invoker
class CommandManager
{
public:
    void execute(std::unique_ptr<ICommand> cmd) {
        cmd->execute();
        undoStack_.push(std::move(cmd));
    }

    void undo() {
        if (!undoStack_.empty()) {
            auto cmd = std::move(undoStack_.top());
            undoStack_.pop();
            cmd->undo();
        }
    }

private:
    std::stack<std::unique_ptr<ICommand>> undoStack_;
};

int main()
{
    TextDocument doc;
    CommandManager mgr;

    mgr.execute(std::make_unique<InsertCommand>(doc, "Hello "));
    mgr.execute(std::make_unique<InsertCommand>(doc, "World!"));

    doc.show();

    mgr.undo();
    doc.show();
}
