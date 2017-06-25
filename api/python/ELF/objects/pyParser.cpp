/* Copyright 2017 R. Thomas
 * Copyright 2017 Quarkslab
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "pyELF.hpp"

#include "LIEF/ELF/Parser.hpp"

#include <string>

void init_ELF_Parser_class(py::module& m) {

  // Parser (Parser)
  m.def("parse",
    static_cast<Binary* (*) (const std::string&, DYNSYM_COUNT_METHODS)>(&Parser::parse),
    "Parse the given binary and return a " RST_CLASS_REF(lief.ELF.Binary) " object\n\n"
    "For *weird* binaries (e.g sectionless) you can choose the method to use to count dynamic symbols "
    " (" RST_CLASS_REF(lief.ELF.DYNSYM_COUNT_METHODS) ")",
    "filename"_a, py::arg("dynsym_count_method") = DYNSYM_COUNT_METHODS::COUNT_AUTO,
    py::return_value_policy::take_ownership);

  m.def("parse",
    static_cast<Binary* (*) (const std::vector<uint8_t>&, const std::string&, DYNSYM_COUNT_METHODS)>(&Parser::parse),
    "Parse the given binary and return a " RST_CLASS_REF(lief.ELF.Binary) " object\n\n"
    "For *weird* binaries (e.g sectionless) you can choose the method to use to count dynamic symbols "
    " (" RST_CLASS_REF(lief.ELF.DYNSYM_COUNT_METHODS) ")",
    "raw"_a, py::arg("name") = "", py::arg("dynsym_count_method") = DYNSYM_COUNT_METHODS::COUNT_AUTO,
    py::return_value_policy::take_ownership);
}
