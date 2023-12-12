#ifndef FLOW_HANDLE_HPP
#define FLOW_HANDLE_HPP

#include "Flow.hpp"
#include "FlowImpl.hpp"
#include "HandleBody.hpp"

#include <string>

template <typename T>
class FlowHandle : public Flow, public Handle<T>{
	public:
		FlowHandle(std::string name = "", System* source = nullptr, System* target = nullptr){
			Handle<T>::pImpl_->setName(name);
			Handle<T>::pImpl_->setSource(source);
			Handle<T>::pImpl_->setTarget(target);
		}

		double execute() {
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

#endif