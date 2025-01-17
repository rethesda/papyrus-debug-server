#pragma once

#include "GameInterfaces.h"

#include "protocol/protocol.h"
#include "StateNodeBase.h"

namespace DarkId::Papyrus::DebugServer
{
	class ArrayStateNode : public StateNodeBase, public IProtocolVariableSerializable, public IStructuredState
	{
		std::string m_name;

		RE::BSTSmartPointer<RE::BSScript::Array> m_value;
		RE::BSScript::Type* m_type;
	public:
		ArrayStateNode(std::string name, RE::BSScript::Array* value, RE::BSScript::Type* type);

		bool SerializeToProtocol(Variable& variable) override;

		bool GetChildNames(std::vector<std::string>& names) override;
		bool GetChildNode(std::string name, std::shared_ptr<StateNodeBase>& node) override;
	};
}