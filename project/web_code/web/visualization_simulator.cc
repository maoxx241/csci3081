/**
 * @file visualization_simulator.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "visualization_simulator.h"


#include "bus_factory.h"
#include "route.h"


VisualizationSimulator::VisualizationSimulator(WebInterface* webI,
        ConfigManager* configM) {
    webInterface_ = webI;
    configManager_ = configM;
}

VisualizationSimulator::~VisualizationSimulator() {
}

void VisualizationSimulator::Start(const std::vector<int>& busStartTimings,
        const int& numTimeSteps) {
    busStartTimings_ = busStartTimings;
    numTimeSteps_ = numTimeSteps;
    context_ = Context();

    timeSinceLastBus_.resize(busStartTimings_.size());
    for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
        timeSinceLastBus_[i] = 0;
    }

    simulationTimeElapsed_ = 0;

    prototypeRoutes_ = configManager_->GetRoutes();
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
        prototypeRoutes_[i]->Report(std::cout);

        prototypeRoutes_[i]->UpdateRouteData();
        webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());
    }
}
void VisualizationSimulator::Pause() {
    if (pause) {
        pause = false;
        return;
    }
    pause = true;
}
void VisualizationSimulator::Update() {
    if (pause) {
      return;
    }
    simulationTimeElapsed_++;
    BusFactory bf;
    std::cout << "~~~~~~~~~~ The time is now " << simulationTimeElapsed_;
    std::cout << "~~~~~~~~~~" << std::endl;

    std::cout << "~~~~~~~~~~ Generating new busses if needed ";
    std::cout << "~~~~~~~~~~" << std::endl;

    // Check if we need to generate new busses
    for (int i = 0; i < static_cast<int>(timeSinceLastBus_.size()); i++) {
        // Check if we need to make a new bus
        if (0 >= timeSinceLastBus_[i]) {
            Route * outbound = prototypeRoutes_[2 * i];
            Route * inbound = prototypeRoutes_[2 * i + 1];
            time_t timer;
            struct tm * timeinfo;
            time(&timer);
            timeinfo = localtime(&timer);
            int hour = timeinfo->tm_hour;
            int min = timeinfo->tm_min;
            std::cout << "~~~~~~~~~~ Current Time is " << hour << " " << min;
            std::cout << "~~~~~~~~~~" << std::endl;
            context_.set_HT(hour);
            context_.report();
            busses_.push_back(bf.Generate(std::to_string(busId),
                outbound->Clone(), inbound->Clone(), context_.Do(), 1));
            busId++;

            timeSinceLastBus_[i] = busStartTimings_[i];
        } else {
            timeSinceLastBus_[i]--;
        }
    }

    std::cout << "~~~~~~~~~ Updating busses ";
    std::cout << "~~~~~~~~~" << std::endl;

    // Update busses
    for (int i = static_cast<int>(busses_.size()) - 1; i >= 0; i--) {
        busses_[i]->Update();

        BusInt *cc = new BusDecorator(busses_[i]);
        cc->SetColor();
        delete cc;

        if (busses_[i]->IsTripComplete()) {
            webInterface_->UpdateBus(busses_[i]->GetBusData(), true);
            busses_.erase(busses_.begin() + i);
            continue;
        }

        webInterface_->UpdateBus(busses_[i]->GetBusData());
        Util *instance;
        std::ostringstream ostr;
        FileWriter fw= FileWriterManager::Getinstance();
        busses_[i]->Report(std::cout);
        busses_[i]->Tocsv(ostr);
        fw.Write(bus_stats_file_name, instance->processOutput(&ostr));
    }

    std::cout << "~~~~~~~~~ Updating routes ";
    std::cout << "~~~~~~~~~" << std::endl;
    // Update routes
    for (int i = 0; i < static_cast<int>(prototypeRoutes_.size()); i++) {
        prototypeRoutes_[i]->Update();

        webInterface_->UpdateRoute(prototypeRoutes_[i]->GetRouteData());

        prototypeRoutes_[i]->Report(std::cout);
    }
}

void VisualizationSimulator::ClearBusListeners() {
    for (int i = static_cast<int>(busses_.size()) - 1; i >= 0; i--) {
        busses_[i]->ClearObservers();
    }
}

void VisualizationSimulator::AddBusListener(std::string *id, IObserver<BusData> *observer) {
    for (int i = static_cast<int>(busses_.size()) - 1; i >= 0; i--) {
        if (busses_[i]->GetName() == *id) {
            busses_[i]->RegosterObserver(observer);
        }
    }
}

void VisualizationSimulator::ClearStopListeners(){
    for (int i = static_cast<int>(prototypeRoutes_.size()) - 1; i >= 0; i--) {
        prototypeRoutes_[i]->ClearObservers();
    }
}

void VisualizationSimulator::AddStopListener(std::string *id, IObserver<StopData> *observer){
    for (int i = static_cast<int>(prototypeRoutes_.size()) - 1; i >= 0; i--) {
        RouteData rd=prototypeRoutes_[i]->GetRouteData();
        for(int j=static_cast<int>(rd.stops.size()) - 1; j >= 0; j--){
            if (rd.stops[j].id == *id) {
            prototypeRoutes_[i]->RegosterObserver(observer);
            prototypeRoutes_[i]->obid_=atoi((*id).c_str());
        }
        }
    }
}

