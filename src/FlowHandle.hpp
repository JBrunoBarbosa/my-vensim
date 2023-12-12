/**
 * @class FlowHandle
 * @brief Classe que representa um manipulador de fluxo genérico.
 *
 * @tparam T O tipo de implementação de fluxo.
 */

#include "Flow.hpp"
#include "HandleBody.hpp"
#include <string>

template <typename T>
class FlowHandle : public Flow, public Handle<T> {
public:
    
    FlowHandle(std::string name = "", System* source = nullptr, System* target = nullptr) {
        Handle<T>::pImpl_->setName(name);
        Handle<T>::pImpl_->setSource(source);
        Handle<T>::pImpl_->setTarget(target);
    }

    double execute() override {
        return Handle<T>::pImpl_->execute();
    }

    void link(System* source, System* target) {
        Handle<T>::pImpl_->link(source, target);
    }

    void setSource(System* source) {
        Handle<T>::pImpl_->setSource(source);
    }

    void setTarget(System* target) {
        Handle<T>::pImpl_->setTarget(target);
    }

    void setName(const std::string name) {
        Handle<T>::pImpl_->setName(name);
    }

    std::string getName() const {
        return Handle<T>::pImpl_->getName();
    }

    System* getSource() const {
        return Handle<T>::pImpl_->getSource();
    }

    System* getTarget() const {
        return Handle<T>::pImpl_->getTarget();
    }
};
