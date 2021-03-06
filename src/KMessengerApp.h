//
// The model implementation for the Messenger application.
//
// @author : Asanga Udugama (adu@comnets.uni-bremen.de), Anna Förster (afoerster@uni-bremen.de)
// @date   : 15-aug-2016, updated 6-febr-2018
//
//

#ifndef KMESSENGERAPP_H_
#define KMESSENGERAPP_H_

#include <omnetpp.h>
#include <cstdlib>
#include <ctime>
#include <list>
#include <string>

#include "KOPSMsg_m.h"
#include "KInternalMsg_m.h"

#if OMNETPP_VERSION >= 0x500
using namespace omnetpp;
#endif

using namespace std;

class KBaseNodeInfo;

#define KMESSENGERAPP_SIMMODULEINFO         " KMessengerApp>!<" << simTime() << ">!<" << getParentModule()->getFullName()
#define TRUE                                1
#define FALSE                               0
#define KMESSENGERAPP_MSGTYPE_NONE          0
#define KMESSENGERAPP_MSGTYPE_IMMEDIATE     1
#define KMESSENGERAPP_MSGTYPE_PREFERENCE    2
#define KMESSENGERAPP_START_ITEM_ID         22000
#define KMESSENGERAPP_REGISTRATION_EVENT	92
#define KMESSENGERAPP_DATASEND_EVENT		93
#define KMESSENGERAP_PER_STAT_EVENT         94


class KMessengerApp : public cSimpleModule
{
    public:
        virtual void initialize(int stage);
        virtual void handleMessage(cMessage *msg);
        virtual int numInitStages() const;
        virtual void finish();

    private:
        string ownMACAddress;

        double totalSimulationTime;
        char prefixName[128] = "/messenger";

		double ttl;
        int nodeIndex;
        int totalNumNodes;
        double dataGenerationInterval;
        int notificationCount;
        vector<int> timesMessagesReceived;
        
        int nextGenerationIndex;

        int usedRNG;

        bool singleDestination;
        string singleDestinationNodeName;

        cMessage *appRegistrationEvent;
        cMessage *dataTimeoutEvent;

        int dataSizeInBytes;

        KBaseNodeInfo* ownNodeInfo;
        bool ownNodeIsDestination;
        KBaseNodeInfo* destinationNodeInfo;

        
        // variables to generate signals

        simsignal_t likedDataBytesReceivedSignal;
        simsignal_t nonLikedDataBytesReceivedSignal;
        simsignal_t duplicateDataBytesReceivedSignal;
        simsignal_t totalDataBytesReceivedSignal;

        simsignal_t likedDataBytesMaxReceivableSignal;
        simsignal_t nonLikedDataBytesMaxReceivableSignal;
        simsignal_t totalDataBytesMaxReceivableSignal;

        simsignal_t likedDataCountReceivedSignal;
        simsignal_t nonLikedDataCountReceivedSignal;
        simsignal_t duplicateDataCountReceivedSignal;
        simsignal_t totalDataCountReceivedSignal;

        simsignal_t likedDataCountMaxReceivableSignal;
        simsignal_t nonLikedDataCountMaxReceivableSignal;
        simsignal_t totalDataCountMaxReceivableSignal;


        simsignal_t likedDataReceivedDelaySignal;
        simsignal_t nonLikedDataReceivedDelaySignal;
        simsignal_t totalDataReceivedDelaySignal;

        simsignal_t likedDataCountReceivedForAvgDelayCompSignal;
        simsignal_t nonLikedDataCountReceivedForAvgDelayCompSignal;
        simsignal_t totalDataCountReceivedForAvgDelayCompSignal;



        simsignal_t likedDataCountReceivedForRatioCompSignal;
        simsignal_t nonLikedDataCountReceivedForRatioCompSignal;
        simsignal_t totalDataCountReceivedForRatioCompSignal;

        simsignal_t likedDataCountMaxReceivableForRatioCompSignal;
        simsignal_t nonLikedDataCountMaxReceivableForRatioCompSignal;
        simsignal_t totalDataCountMaxReceivableForRatioCompSignal;



        simsignal_t likedDataHopsForAvgHopsCompSignal;
        simsignal_t nonLikedDataHopsForAvgHopsCompSignal;
        simsignal_t totalDataHopsForAvgHopsCompSignal;

        simsignal_t likedDataHopsCountForAvgHopsCompSignal;
        simsignal_t nonLikedDataHopsCountForAvgHopsCompSignal;
        simsignal_t totalDataHopsCountForAvgHopsCompSignal;

        // special signals
        simsignal_t likedDataReceivedDelaySignal2;
        simsignal_t nonLikedDataReceivedDelaySignal2;
        simsignal_t totalDataReceivedDelaySignal2;

        simsignal_t totalDataBytesReceivedSignal2;
        simsignal_t totalDataCountReceivedSignal2;

};


#endif /* KMESSENGERAPP_H_ */
