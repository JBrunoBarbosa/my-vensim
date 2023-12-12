/**
 * @class FlowImpl
 * @brief Classe que implementa Flow.
 */
#ifndef FLOW_IMPL_HPP
#define FLOW_IMPL_HPP

#include "System.hpp"
#include "HandleBody.hpp"

class FlowImpl : public Body {
protected:
    std::string name;
    System* source;
    System* target;

public:
    FlowImpl(std::string name = "", System* source = nullptr, System* target = nullptr);
    FlowImpl(const FlowImpl& other);
    virtual ~FlowImpl();
    virtual double execute() = 0;
    void link(System* source, System* target);
    void setSource(System* source);
    void setTarget(System* target);
    void setName(const std::string name) ;
    std::string getName() const;
    System* getSource() const;
    System* getTarget() const;
    FlowImpl& operator=(const FlowImpl& other);
};

#endif
