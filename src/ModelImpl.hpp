/**
 * @class ModelImpl
 * @brief Classe que implementa Model.
 */
#ifndef MODELIMPL_HPP
#define MODELIMPL_HPP

#include "Model.hpp"
#include "HandleBody.hpp"

class ModelImpl : public Body {
protected:
    std::vector<Flow*> flows;
    std::vector<System*> systems;
    std::vector<std::vector<double>> history;

public:
    ModelImpl();
    ModelImpl(Model* other);
    virtual ~ModelImpl();

    typedef std::vector<System *>::iterator systemIterator;
    typedef std::vector<Flow *>::iterator flowIterator;
    typedef std::vector<std::vector<double>>::iterator historyIterator;

    systemIterator beginSystems();
    systemIterator endSystems();
    flowIterator beginFlows();
    flowIterator endFlows();
    historyIterator beginHistory();
    historyIterator endHistory();
    System* createSystem(const std::string name, double value);
    void deleteSystem(System* const system);
    void deleteFlow(Flow* const flow);
    void add(Flow* flow);
    void add(System* system);
    void report();
    void setInitialHistory();
    void execute(const int timeInitial, const int timeFinal);
};

#endif