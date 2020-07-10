#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "DeReplicatePlugin.h"

void DeReplicatePlugin::input(std::string file) {
 inputfile = file;
}

void DeReplicatePlugin::run() {}

void DeReplicatePlugin::output(std::string file) {
//-cluster_fast HMP_MOCK.v35.fasta -id 0.9 -centroids nr.fasta
 std::string outputfile = file;
 std::string myCommand = "";
myCommand += "usearch -fastx_uniques ";
myCommand += inputfile;
myCommand += " -fastaout ";
myCommand += outputfile;
myCommand += " -sizeout -relabel Uniq";
std::cout<<myCommand<<std::endl;
 system(myCommand.c_str());
}

PluginProxy<DeReplicatePlugin> DeReplicatePluginProxy = PluginProxy<DeReplicatePlugin>("DeReplicate", PluginManager::getInstance());
