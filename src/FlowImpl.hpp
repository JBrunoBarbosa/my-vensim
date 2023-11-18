// FlowImpl.hpp
#ifndef FLOW_IMPL_HPP
#define FLOW_IMPL_HPP

#include "System.hpp"
#include "Flow.hpp"

using namespace std;

class FlowImpl : public Flow {
protected:
    string name;
    System* source;
    System* target;

public:
    FlowImpl(string name = "", System* source = nullptr, System* target = nullptr);
    FlowImpl(const FlowImpl& other);
    virtual ~FlowImpl();
    virtual double execute() override = 0;
    void link(System* source, System* target) override;
    void setSource(System* source) override;
    void setTarget(System* target) override;
    void setName(const string name) override;
    string getName() const override;
    System* getSource() const override;
    System* getTarget() const override;
    Flow& operator=(const Flow& other);
};

#endif
