#ifndef MODELIMPL_HPP
#define MODELIMPL_HPP

#include "Model.hpp"

class ModelImpl : public Model {
protected:
    vector<Flow*> flows;
    vector<System*> systems;
    vector<vector<double>> history;

public:
    ModelImpl();
    ModelImpl(Model* other);
    virtual ~ModelImpl();

    systemIterator beginSystems() override;
    systemIterator endSystems() override;
    flowIterator beginFlows() override;
    flowIterator endFlows() override;
    historyIterator beginHistory() override;
    historyIterator endHistory() override;
    void add(Flow* flow) override;
    void add(System* system) override;
    void report() override;
    void setInitialHistory() override;
    void clearModel() override;
    void execute(const int timeInitial, const int timeFinal) override;
};

#endif