/**
 * @class ModelHandle
 * @brief Classe que implementa o Handle de Model.
 */
#ifndef MODEL_HANDLE_HPP
#define MODEL_HANDLE_HPP

#include "Model.hpp"
#include "ModelImpl.hpp"
#include "HandleBody.hpp"

class ModelHandle : public Model, public Handle<ModelImpl> {
public:
    systemIterator beginSystems() {
        return pImpl_->beginSystems();
    }

    systemIterator endSystems() {
        return pImpl_->endSystems();
    }

    flowIterator beginFlows() {
        return pImpl_->beginFlows();
    }

    flowIterator endFlows() {
        return pImpl_->endFlows();
    }

    historyIterator beginHistory() {
        return pImpl_->beginHistory();
    }

    historyIterator endHistory() {
        return pImpl_->endHistory();
    }

    System* createSystem(const std::string name, double value) {
        return pImpl_->createSystem(name, value);
    }

    void add(Flow* flow) {
        pImpl_->add(flow);
    }

    void add(System* system) {
        pImpl_->add(system);
    }

    void report() {
        pImpl_->report();
    }

    void setInitialHistory() {
        pImpl_->setInitialHistory();
    }

    void execute(const int timeInitial, const int timeFinal) {
        pImpl_->execute(timeInitial, timeFinal);
    }

    void deleteSystem(System* const system) {
        pImpl_->deleteSystem(system);
    }

    void deleteFlow(Flow* const flow) {
        pImpl_->deleteFlow(flow);
    }
};

#endif