#ifndef SYSTEM_HANDLE_HPP
#define SYSTEM_HANDLE_HPP

#include "SystemImpl.hpp"
#include "HandleBody.hpp"

#include <string>

class SystemHandle : public System, public Handle<SystemImpl>{
	public:
		SystemHandle(std::string name = "", double value = 0){
			pImpl_->setName(name);
			pImpl_->setValue(value);
		}

		void setValue(const double value) {
			return pImpl_->setValue(value);
		}

		void setName(const std::string name) {
			return pImpl_->setName(name);
		}

		double getValue(void) const {
			return pImpl_->getValue();
		}

		std::string getName(void) const {
			return pImpl_->getName();
		}
};

#endif