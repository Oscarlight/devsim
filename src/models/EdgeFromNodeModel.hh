/***
DEVSIM
Copyright 2013 Devsim LLC

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
***/

#ifndef EDGEFROMNODEMODEL_HH
#define EDGEFROMNODEMODEL_HH
#include "EdgeModel.hh"

#include <memory>

class NodeModel;
typedef std::weak_ptr<NodeModel>         WeakNodeModelPtr;
typedef std::shared_ptr<NodeModel>       NodeModelPtr;
typedef std::shared_ptr<const NodeModel> ConstNodeModelPtr;

#include <string>
// This class relies on a parent Node Model for it's data.  It provides conversion so that a node model may be projected onto both sides of an edge.
// An edge sub model is used for node_1, if it is necessary
class EdgeFromNodeModel : public EdgeModel
{
    public:
        // This model depends on this Node model to calculate values
        EdgeFromNodeModel(const std::string &/*node 0 modelname*/, const std::string &/*node 1 modelname*/, const std::string &/*nodemodel*/, RegionPtr);
        ~EdgeFromNodeModel();

        void Serialize(std::ostream &) const;

    private:
        double calcSolution(ConstEdgePtr) const;
        void calcEdgeScalarValues() const;
        void setInitialValues();
        // If we are an auxilary model, create our values from the parent
        // Actually this should be by name and not by pointer reference
        // Need to do the same from EdgeSubModel, and NodeSolution
        const std::string nodeModelName;
        // This is for the second node on the edge
        mutable WeakEdgeModelPtr node1EdgeModel;
        const   std::string edgeModel1Name;
};

#endif

