#include <boost/asio.hpp>
#include <gflags/gflags.h>
#include <glog/logging.h>

#include <iostream>
#include <functional>

DEFINE_bool(run_io_service, true, "Run the io_service object.");

int main(int argc, char* argv[]) {
    gflags::SetUsageMessage("");
    gflags::SetVersionString("0.0.2");
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    boost::asio::io_service io_service;
    io_service.post([](){
        std::cout << "Running async method" << std::endl;
    });

    if (FLAGS_run_io_service) {
        std::cout << "Before io_service::run" << std::endl;
        std::cout << "--------" << std::endl;
        io_service.run();
        std::cout << "--------" << std::endl;
        std::cout << "After io_service::run" << std::endl;
    }

    return 0;
}
