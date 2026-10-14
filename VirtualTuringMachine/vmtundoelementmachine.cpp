#include "vmtundoelementmachine.h"

#include <qstringview.h>

#include <QDebug>

#include "VMTJsonSerializer.h"
#include "vmtproject.h"

VMTUndoElementMachine::VMTUndoElementMachine() {
    _array = VMTJsonSerializer::serializeInMemory(&VMTProject::GetInstance());
}

void VMTUndoElementMachine::Undo(IVMTEnvironment*) {
    VMTJsonSerializer::deserializeFromMemory(&VMTProject::GetInstance(),
                                             _array);
}

VMTUndoElementMachine::~VMTUndoElementMachine() {}
