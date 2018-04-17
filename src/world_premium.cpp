#include "ScriptMgr.h"
#include "Configuration/Config.h"
#include "included_scripts.h"

class world_premium : public WorldScript
{
public:
    world_premium() : WorldScript("world_premium") { }

    void OnBeforeConfigLoad(bool reload) override
    {
        if (!reload) {
            std::string cfg_file = "premium.conf";
            std::string cfg_def_file = cfg_file + ".dist";

            sConfigMgr->LoadMore(cfg_def_file.c_str());
            sConfigMgr->LoadMore(cfg_file.c_str());
        }
    }
};

void AddSC_world_premium()
{
    new world_premium();
}