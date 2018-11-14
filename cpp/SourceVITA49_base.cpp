#include "SourceVITA49_base.h"

/*******************************************************************************************

    AUTO-GENERATED CODE. DO NOT MODIFY

    The following class functions are for the base class for the component class. To
    customize any of these functions, do not modify them here. Instead, overload them
    on the child class

******************************************************************************************/

SourceVITA49_base::SourceVITA49_base(const char *uuid, const char *label) :
    Component(uuid, label),
    ThreadedComponent()
{
    setThreadName(label);

    loadProperties();

    dataVITA49_in = new bulkio::InVITA49Port("dataVITA49_in");
    dataVITA49_in->setLogger(this->_baseLog->getChildLogger("dataVITA49_in", "ports"));
    addPort("dataVITA49_in", dataVITA49_in);
    dataChar_out = new bulkio::OutCharPort("dataChar_out");
    dataChar_out->setLogger(this->_baseLog->getChildLogger("dataChar_out", "ports"));
    addPort("dataChar_out", dataChar_out);
    dataOctet_out = new bulkio::OutOctetPort("dataOctet_out");
    dataOctet_out->setLogger(this->_baseLog->getChildLogger("dataOctet_out", "ports"));
    addPort("dataOctet_out", dataOctet_out);
    dataShort_out = new bulkio::OutShortPort("dataShort_out");
    dataShort_out->setLogger(this->_baseLog->getChildLogger("dataShort_out", "ports"));
    addPort("dataShort_out", dataShort_out);
    dataUshort_out = new bulkio::OutUShortPort("dataUshort_out");
    dataUshort_out->setLogger(this->_baseLog->getChildLogger("dataUshort_out", "ports"));
    addPort("dataUshort_out", dataUshort_out);
    dataFloat_out = new bulkio::OutFloatPort("dataFloat_out");
    dataFloat_out->setLogger(this->_baseLog->getChildLogger("dataFloat_out", "ports"));
    addPort("dataFloat_out", dataFloat_out);
    dataDouble_out = new bulkio::OutDoublePort("dataDouble_out");
    dataDouble_out->setLogger(this->_baseLog->getChildLogger("dataDouble_out", "ports"));
    addPort("dataDouble_out", dataDouble_out);
}

SourceVITA49_base::~SourceVITA49_base()
{
    dataVITA49_in->_remove_ref();
    dataVITA49_in = 0;
    dataChar_out->_remove_ref();
    dataChar_out = 0;
    dataOctet_out->_remove_ref();
    dataOctet_out = 0;
    dataShort_out->_remove_ref();
    dataShort_out = 0;
    dataUshort_out->_remove_ref();
    dataUshort_out = 0;
    dataFloat_out->_remove_ref();
    dataFloat_out = 0;
    dataDouble_out->_remove_ref();
    dataDouble_out = 0;
}

/*******************************************************************************************
    Framework-level functions
    These functions are generally called by the framework to perform housekeeping.
*******************************************************************************************/
void SourceVITA49_base::start() throw (CORBA::SystemException, CF::Resource::StartError)
{
    Component::start();
    ThreadedComponent::startThread();
}

void SourceVITA49_base::stop() throw (CORBA::SystemException, CF::Resource::StopError)
{
    Component::stop();
    if (!ThreadedComponent::stopThread()) {
        throw CF::Resource::StopError(CF::CF_NOTSET, "Processing thread did not die");
    }
}

void SourceVITA49_base::releaseObject() throw (CORBA::SystemException, CF::LifeCycle::ReleaseError)
{
    // This function clears the component running condition so main shuts down everything
    try {
        stop();
    } catch (CF::Resource::StopError& ex) {
        // TODO - this should probably be logged instead of ignored
    }

    Component::releaseObject();
}

void SourceVITA49_base::loadProperties()
{
    addProperty(interface,
                "eth1",
                "interface",
                "",
                "readwrite",
                "",
                "external",
                "configure");

    addProperty(attachment_override,
                attachment_override_struct(),
                "attachment_override",
                "",
                "readwrite",
                "",
                "external",
                "configure");

    addProperty(connection_status,
                connection_status_struct(),
                "connection_status",
                "",
                "readonly",
                "",
                "external",
                "configure");

    addProperty(VITA49Processing_override,
                VITA49Processing_override_struct(),
                "VITA49Processing_override",
                "",
                "readwrite",
                "",
                "external",
                "configure");

    addProperty(advanced_configuration,
                advanced_configuration_struct(),
                "advanced_configuration",
                "",
                "readwrite",
                "",
                "external",
                "configure");

}


