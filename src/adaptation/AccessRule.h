#ifndef SQUID_ADAPTATION__ACCESS_RULE_H
#define SQUID_ADAPTATION__ACCESS_RULE_H

#include "SquidString.h"
#include "adaptation/forward.h"

class acl_access;

namespace Adaptation {

// manages adaptation_access configuration by associating an acl with
// an adaptation service group
class AccessRule {
public:
    AccessRule();
    ~AccessRule();

    void parse(ConfigParser &parser);
    void finalize();

    // service group consisting of one or more services
    ServiceGroup *group();

public:
    typedef int Id;
    const Id id;
    String groupId;
    acl_access *acl;

private:
    static Id LastId;
};

typedef Vector<Adaptation::AccessRule*> AccessRules;
extern AccessRules &AllRules();
extern AccessRule *FindRule(const AccessRule::Id &id);

} // namespace Adaptation

#endif /* SQUID_ADAPTATION__ACCESS_RULE_H */
