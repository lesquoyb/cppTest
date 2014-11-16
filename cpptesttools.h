#ifndef CppTestTOOLS_H
#define CppTestTOOLS_H


#define diffND(arg1,arg2)           return diffNDFun(arg1,arg2)
#define diff(arg1,arg2)             return diffFun(arg1,arg2)
#define nEqualsND(arg1,arg2)        return !(arg1 == arg2)
#define equalsND(arg1,arg2)         return arg1 == arg2
#define equals(arg1,arg2)           return equalsFun(arg1,arg2)
#define nEquals(arg1,arg2)          return notEqualsFun(arg1,arg2)
#define errorExpected(func)         try{ auto test = [&]()func; test();return false;}catch(exception e){return true;}
//#define expected(error,func)        try{ auto test = [&]()func;test();return false;}catch(error e){return true;} //TODO
#define CPPTEST(unitName) class unitName : public CppTest {  public: unitName(){ CppTest::_name = #unitName;
#define ENDTEST run();}};
#define TESTCASE(name,content)   std::function<bool()> name = [&]() content ;\
                                    _functions.push_back(name);\
                                    _names.push_back(#name);

template<class T1, class T2>
/**
 * @brief equals
 * equality function which uses operator== and operator<< to cout the values if they are not equal.
 * @param arg1
 * @param arg2
 * @return
 */
bool equalsFun(T1 arg1, T2 arg2){
    if( arg1 == arg2) return true;
    std::cout << "arg1: " << arg1 <<"arg2: " << arg2;
    return false;
}



template<class T1, class T2>
/**
 * @brief not equals
 * Inequality function which uses operator== and operator<< to cout the values if they are equal.
 * @param arg1
 * @param arg2
 * @return
 */
bool notEqualsFun(T1 arg1, T2 arg2){
    if(!( arg1 == arg2)) return true;
    std::cout << "arg1: " << arg1 <<"arg2: " << arg2;
    return false;
}



template<class T1, class T2>
/**
 * @brief diff
 * Function which returns true if arguments are different using operator!= and operator<<
 * @param arg1
 * @param arg2
 * @return
 */
bool diffFun(T1 arg1, T2 arg2){
    if (arg1 != arg2) return true;
    std::cout << "arg1 " << arg1 << "arg2 " << arg2;
    return false;
}


template<class T1, class T2>
/**
 * @brief diff
 * Function which returns true if arguments are different using operator!=
 * @param arg1
 * @param arg2
 * @return
 */
bool diffNDFun(T1 arg1, T2 arg2){
    if (arg1 != arg2) return true;
    return false;
}

#endif // CppTestTOOLS_H
