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

#include "TetrahedronEdgeScalarData.hh"
#include "TetrahedronEdgeModel.hh"
#include "ScalarData.cc"

//// Manual Template Instantiation
template class ScalarData<TetrahedronEdgeModel>;

template class
ScalarData<TetrahedronEdgeModel>& ScalarData<TetrahedronEdgeModel>::op_equal<ScalarDataHelper::times_equal>(const double &, const ScalarDataHelper::times_equal &);

template class
ScalarData<TetrahedronEdgeModel>& ScalarData<TetrahedronEdgeModel>::op_equal<ScalarDataHelper::times_equal>(const ScalarData<TetrahedronEdgeModel> &, const ScalarDataHelper::times_equal &);

template class
ScalarData<TetrahedronEdgeModel>& ScalarData<TetrahedronEdgeModel>::op_equal<ScalarDataHelper::plus_equal>(const double &, const ScalarDataHelper::plus_equal &);

template class
ScalarData<TetrahedronEdgeModel>& ScalarData<TetrahedronEdgeModel>::op_equal<ScalarDataHelper::plus_equal>(const ScalarData<TetrahedronEdgeModel> &, const ScalarDataHelper::plus_equal &);

