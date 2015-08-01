#include <Engine/Agent.hpp>

class StudentAgent : public Engine::Agent {
public:
    StudentAgent(void);
    StudentAgent(unsigned x, unsigned y);
    ~StudentAgent(void);

    QString getDesc(void) { return "StudentAgent"; }
    bool isDrawable(void) { return true; }
protected:
    const QString className = "StudentAgent";
//    const bool drawable = true;
};
