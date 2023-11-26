/**
 * @class FlowImpl
 * @brief Classe que implementa Flow.
 */
#ifndef FLOW_IMPL_HPP
#define FLOW_IMPL_HPP

#include "System.hpp"
#include "Flow.hpp"

class FlowImpl : public Flow {
protected:
    std::string name;
    System* source;
    System* target;

public:
    FlowImpl(std::string name = "", System* source = nullptr, System* target = nullptr);
    FlowImpl(const FlowImpl& other);
    virtual ~FlowImpl();
    virtual double execute() override = 0;
    void link(System* source, System* target) override;
    void setSource(System* source) override;
    void setTarget(System* target) override;
    void setName(const std::string name) override;
    std::string getName() const override;
    System* getSource() const override;
    System* getTarget() const override;
    Flow& operator=(const Flow& other);
};

#endif
