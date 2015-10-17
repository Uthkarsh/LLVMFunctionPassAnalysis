#include "passes.h"

namespace {
   struct FunctionPassAnalysis : public ModulePass 
  {

	static const char* getType(int ID)
	{

	
		switch(ID)
			{

				case 0:   return "void";
						  break;
				case 1:
	 					  return "float";
						  break;
	          	case 2:
	          			  return "float";
						  break;
	          	case 3:
	          			  return "double";
					      break;
		        case 10:
		          	      return "int";
						  break;
		       	case 11:
		          		  return "fnuction";
						  break;
		        case 12:
		          		  return "structure";
						  break;
		        case 13:
		          		  return "array";
						  break;
		        case 14:
		         		  return "pointer";
						  break;

		        default:
		          		  return "Type undefined"; 
			}
	}

    int check(int type)
    {
     return (type == 1 || type == 2 || type == 3 || type == 10);

    }
    static char ID;
    FunctionPassAnalysis() : ModulePass(ID) 
    {

    }

    virtual bool runOnModule(Module &M){

    	for (auto funcList = M.begin(), funcListEnd = M.end();funcList != funcListEnd; ++funcList) 
    	{
    		for (Function::iterator itBlock = *funcList->begin(), e = *funcList->end(); itBlock != e; ++itBlock)

    			for (auto inst = itBlock->begin(), eb = itBlock->end(); inst != eb; ++inst)
    			{
    				if(isa<CallInst>(inst))
    				{
    					const CallInst *instr = dyn_cast<CallInst>(&*inst);
						const Function * func = dyn_cast<const Function>(instr->getCalledValue()->stripPointerCasts());
    					
						 if (!(func->isDeclaration()) )
    					 {
    						int nArgCaller=instr->getNumArgOperands();
    						int nArgPT=func->getFunctionType()->getNumParams();

    						 StringRef name = func->getName();
    						 MDNode *NODE = instr->getMetadata("dbg");
    						 DILocation dil = DILocation(NODE);
    						 int line_no = dil.getLineNumber();
                             //errs()<<"Line number is:"<<line_no;
    						if(nArgCaller != nArgPT){
    							errs() << "Function "<<name<<" call on line number:"<<line_no;
                                errs() << " Expected "<<nArgPT<<" arguments but "<<nArgCaller<<" is/are present \n";

    						}
    						else
    						{
    							// Type checking
    						for(int index=0; index<nArgCaller;index++)
    						{

    							int callType = instr->getArgOperand(index)->getType()->getTypeID();
    							//errs()<<instr->getArgOperand(index)->getType()->getTypeID()<<"\n";
    							StringRef call_type ;

								call_type = getType(callType);

    							int nArgPT = func->getFunctionType()->getParamType(index)->getTypeID();
    							StringRef proto_type;

								proto_type = getType(nArgPT);

    							if(callType != nArgPT)
    							{
                                    //errs()<<"callType:"<<callType<<" nArgPT:"<<nArgPT;

    								if(check(callType))
    								{
    									if(check(nArgPT))
    									{
    										errs()<<"warning: ";
    									}
    									else
    										errs()<<"error: ";
    								}
    								//format printing
    								errs() << "Function "<<name<<" call on line number:"<<line_no<<"; Argument type mismatch.";
                                    errs() << " Expected: "<<proto_type.str()<<" type but argument is of type: "<<call_type.str()<<"\n";
    							}

    						}

    					 }
    					 }
    				}
    			}
    		}





      return false;
    }

    
  };


}

char FunctionPassAnalysis::ID = 0;
static RegisterPass<FunctionPassAnalysis> X("FunctionPassAnalysis", "function pass analysis",false,false);
