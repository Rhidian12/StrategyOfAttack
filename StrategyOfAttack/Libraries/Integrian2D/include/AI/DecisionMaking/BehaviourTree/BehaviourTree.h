#pragma once

#include "../../../Integrian2D_API.h"
#include "../BaseDecisionMaking/BaseDecisionMaking.h"

#include <functional>
#include <vector>

namespace Integrian2D
{
	class BehaviourTreeNode
	{
	public:
		INTEGRIAN2D_API virtual ~BehaviourTreeNode() = default;

		INTEGRIAN2D_API virtual BehaviourState Execute(Blackboard* const) const = 0;
	};

	class ActionNode final : public BehaviourTreeNode
	{
	public:
		using Action = std::function<BehaviourState(Blackboard* const)>;

		INTEGRIAN2D_API ActionNode(const Action& action);

		INTEGRIAN2D_API virtual BehaviourState Execute(Blackboard* const pBlackboard) const override;

	private:
		Action m_Action;
	};

	class ConditionalNode final : public BehaviourTreeNode
	{
	public:
		using Predicate = std::function<bool(Blackboard* const)>;

		INTEGRIAN2D_API ConditionalNode(const Predicate& predicate);

		INTEGRIAN2D_API virtual BehaviourState Execute(Blackboard* const pBlackboard) const override;

	private:
		Predicate m_Predicate;
	};

	class InvertedConditionalNode final : public BehaviourTreeNode
	{
	public:
		using Predicate = std::function<bool(Blackboard* const)>;

		INTEGRIAN2D_API InvertedConditionalNode(const Predicate& predicate);

		INTEGRIAN2D_API virtual BehaviourState Execute(Blackboard* const pBlackboard) const override;

	private:
		Predicate m_Predicate;
	};

	class SequenceNode final : public BehaviourTreeNode
	{
	public:
		INTEGRIAN2D_API SequenceNode(const std::vector<BehaviourTreeNode*>& nodes);
		INTEGRIAN2D_API ~SequenceNode();

		INTEGRIAN2D_API virtual BehaviourState Execute(Blackboard* const pBlackboard) const override;

	private:
		std::vector<BehaviourTreeNode*> m_Nodes;
	};

	class BehaviourTree final : public BaseDecisionMaking
	{
	public:
		INTEGRIAN2D_API BehaviourTree(const std::vector<BehaviourTreeNode*>& nodes);
		INTEGRIAN2D_API ~BehaviourTree();

		INTEGRIAN2D_API virtual BehaviourState Update(Blackboard* const pBlackboard) override;

	private:
		std::vector<BehaviourTreeNode*> m_Nodes;
		const BehaviourTreeNode* m_pCurrentNode;
	};
}