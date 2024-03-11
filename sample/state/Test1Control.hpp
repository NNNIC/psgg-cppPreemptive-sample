#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <cstdlib>

#include "StateGoData.hpp"

using namespace std;



class Test1Control 
{
    //region manager 
private:
    
    typedef void (Test1Control::*FUNCPTR)(bool);

    FUNCPTR m_curstate;
    FUNCPTR m_nextstate;
    bool   m_bNoWait;

    StateGoData *m_data;

public:
    enum STATE {
        STATE_NONE,
        //  construction codes                       [STATE-GO OUTPUT START] indent(8) $/^S_/->#estatelist$
        //             psggConverterLib.dll converted from psgg-file:Test1Control.psgg                              // *DoNotEdit*
                                                                            // *DoNotEdit*
        ES_0000,                                                            // *DoNotEdit*
        ES_0001,                                                            // *DoNotEdit*
        ES_0002,                                                            // *DoNotEdit*
        ES_0003,                                                            // *DoNotEdit*
        ES_END,                                                             // *DoNotEdit*
        ES_START,                                                           // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
        //                                           [STATE-GO OUTPUT END]
        STATE_MAX
    };
    STATE m_state;

    FUNCPTR m_statelist[STATE_MAX + 1] = {
        nullptr,
        //  construction codes                       [STATE-GO OUTPUT START] indent(8) $/^S_/->#statelist$
        //             psggConverterLib.dll converted from psgg-file:Test1Control.psgg                              // *DoNotEdit*
                                                                            // *DoNotEdit*
        &Test1Control::S_0000,                                              // *DoNotEdit*
        &Test1Control::S_0001,                                              // *DoNotEdit*
        &Test1Control::S_0002,                                              // *DoNotEdit*
        &Test1Control::S_0003,                                              // *DoNotEdit*
        &Test1Control::S_END,                                               // *DoNotEdit*
        &Test1Control::S_START,                                             // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
        //                                           [STATE-GO OUTPUT END]
        nullptr
    };

private:
    inline int findFuncPtrIndex(FUNCPTR funcptr)
    {
        for (int i = 0; i < STATE_MAX; ++i) {
            if (m_statelist[i] == funcptr) {
                return i;
            }
        }
        return -1;
    }
    int m_end_index;

public :
    Test1Control() : 
    //  construction codes                       [STATE-GO OUTPUT START] indent(8) $/^S_/->#constructlist$
        //             psggConverterLib.dll converted from psgg-file:Test1Control.psgg                              // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
    //                                           [STATE-GO OUTPUT END]
        m_curstate(nullptr), m_nextstate(nullptr), m_bNoWait(false), m_data(nullptr)
	{
		m_end_index = findFuncPtrIndex(&Test1Control::S_END);
	}
	~Test1Control()
	{
	}

private:
    void _update();

    inline void Goto(FUNCPTR st)        { m_nextstate = st;              }
    inline bool CheckState(FUNCPTR st)  { return m_curstate == st;       }
    inline bool HasNextState()          { return m_nextstate != nullptr; }
    inline void NoWait()                { m_bNoWait = true;              }
    //endregion manager

    //  Embed codes                              [STATE-GO OUTPUT START] indent(4) $/^E_/$
    //             psggConverterLib.dll converted from psgg-file:Test1Control.psgg                                  // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
    //                                           [STATE-GO OUTPUT END]

    //  Member codes                              [STATE-GO OUTPUT START] indent(4) $/^S_/->#memberlist$
    //             psggConverterLib.dll converted from psgg-file:Test1Control.psgg                                  // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
    //                                           [STATE-GO OUTPUT END]


    //  API declaration                          [STATE-GO OUTPUT START] indent(4) $/^S_/->#declare$
    //             psggConverterLib.dll converted from psgg-file:Test1Control.psgg                                  // *DoNotEdit*
                                                                            // *DoNotEdit*
    void S_0000(bool bFirst);                                               // *DoNotEdit*
    void S_0001(bool bFirst);                                               // *DoNotEdit*
    void S_0002(bool bFirst);                                               // *DoNotEdit*
    void S_0003(bool bFirst);                                               // *DoNotEdit*
    void S_END(bool bFirst);                                                // *DoNotEdit*
    void S_START(bool bFirst);                                              // *DoNotEdit*
                                                                            // *DoNotEdit*
                                                                            // *DoNotEdit*
    //                                           [STATE-GO OUTPUT END]

public:
    void Start();
    bool IsEnd();
    void Update();

    //Preemptive call
    void PreemptiveInit(StateGoData& data);
    int  PreemptiveCallUpdate(StateGoData& data);
    void PreemptiveCallTest();
};