#pragma once
#include <Analyser.h>
#include <exception>
#include <BaseTypes.h>

namespace O {
	class SematicAnalyser
	{
	private:
		int returnCalls = 0;
		DataTypes returnType = DataTypes::Void;

		std::vector<Variable> variables;
		std::vector<Variable> variablesCreatedAtThatField;
		std::vector<Instruction> instructions;
		std::vector<Function> functions;
		std::vector<Operator> operators = {
			Operator("?", DataTypes::Integer, DataTypes::Integer, DataTypes::Boolean),
			Operator("+", DataTypes::Integer, DataTypes::Integer, DataTypes::Integer),
			Operator("-", DataTypes::Integer, DataTypes::Integer, DataTypes::Integer),
			Operator("*", DataTypes::Integer, DataTypes::Integer, DataTypes::Integer),
			Operator("/", DataTypes::Integer, DataTypes::Integer, DataTypes::Integer),
		};
		
	private:
		// returns ERROR if not found
		DataTypes containsFunction(std::string name, std::vector<DataTypes> dt);
		bool containsVariable(std::string name);
		bool containsOperator(std::string op, DataTypes left, DataTypes right);
		DataTypes getReturnDataTypeOfOperator(std::string op, DataTypes left, DataTypes right);

		Instruction checkAndGetFunction(Analyser::Token token);

		Instruction getVariableAsInstruction(std::string name);

		Instruction proccessInstCall(Analyser::Token token);
	
		Instruction proccessReturnCall(Analyser::Token token);
		Instruction proccessIfInstruction(Analyser::TokenisedFile token);
		Instruction proccessElseIfInstruction(Analyser::TokenisedFile token);
		Instruction proccessElseInstruction(Analyser::TokenisedFile token);
		Instruction proccessFuncInstrucion(Analyser::TokenisedFile token);
		Instruction proccessVarInstruction(Analyser::Token token);
		Instruction proccessSetInstruction(Analyser::Token token);

		Instruction ProcessToken(Analyser::TokenisedFile token, bool add = true);

	public:
		void ProccessTokenisedFile(Analyser::TokenisedFile tf);
		File getFileRepresantation();
	};
}

