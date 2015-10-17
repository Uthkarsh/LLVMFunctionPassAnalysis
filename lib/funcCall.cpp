#include "passes.h"
#include <string>
using namespace llvm;
using namespace std;

#define DEBUG_TYPE "funcCall"

namespace {
struct funcCall : public CallGraphSCCPass {
	static char ID;int counter=0;
funcCall() : CallGraphSCCPass(ID) {}

	bool runOnSCC(CallGraphSCC &SCC) override {
		CallGraph &CG = getAnalysis<CallGraphWrapperPass>().getCallGraph();

		CallGraphSCC::iterator i = SCC.begin();
			if(counter==0)
			{errs() << "List of function calls:" << "\n" ;
			counter++;
			}

		if((*i)->getFunction()){
			if(!((*i)->getFunction()->isDeclaration()))
			{
				CallGraphNode *CGN = CG[(*i)->getFunction()];

				errs().write_escaped((*i)->getFunction()->getName());

				FunctionType *funcType = (*i)->getFunction()->getFunctionType();
				int nArguments = funcType->getNumParams();    

				errs() << "(";
				for(int i=0;i < nArguments;i++)
				{
					string type=" ";
					if(funcType->getParamType(i)->isIntegerTy())
						type = "int";

					if(funcType->getParamType(i)->isVoidTy())
						type = "void";

					if(funcType->getParamType(i)->isFloatTy())
						type = "float";

					if(funcType->getParamType(i)->isDoubleTy())
						type = "double";

					errs()<<type;
					if(i<nArguments-1)
						errs()<<",";

				}

				errs() << ")";
				errs() << ":";
				errs().operator<<(CGN->getNumReferences()-1)<< "\n";

			}
		}

		return false;
		}

	void getAnalysisUsage(AnalysisUsage &AU) const {
		CallGraphSCCPass::getAnalysisUsage(AU);
	}
	};
}
char funcCall::ID = 0;
static RegisterPass<funcCall> X("funcCall", "Counts Nunber of function References");
