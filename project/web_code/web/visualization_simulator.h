/**
 * @file visualization_simulator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef VISUALIZATION_SIMULATOR_H_
#define VISUALIZATION_SIMULATOR_H_

#include <vector>
#include <list>
#include <string>

#include "web_interface.h"
#include "config_manager.h"
#include "iobserver.h"
#include "bus_depot.h"
#include "bus_decorator.h"
#include "bus.h"
#include "route.h"
#include "file_writer_manager.h"
#include "util.h"

class Route;
class Bus;
class Stop;

class VisualizationSimulator {
    public:
        VisualizationSimulator(WebInterface*, ConfigManager*);
        ~VisualizationSimulator();

        void Start(const std::vector<int>&, const int&);
        void Pause();
        void Update();
        void ClearBusListeners();
        void AddBusListener(std::string *id, IObserver<BusData> *observer);
        void ClearStopListeners();
        void AddStopListener(std::string *id, IObserver<StopData> *observer);

    private:
        WebInterface* webInterface_;
        ConfigManager* configManager_;
        Context context_;
        bool pause=false;
        std::vector<int> busStartTimings_;
        std::vector<int> timeSinceLastBus_;
        int numTimeSteps_;
        int simulationTimeElapsed_;

        std::vector<Route *> prototypeRoutes_;
        std::vector<Bus *> busses_;
        std::string bus_stats_file_name = "BusDate.csv";

        int busId = 1000;
};

#endif // VISUALIZATION_SIMULATOR_H_
