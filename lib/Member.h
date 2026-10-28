#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

class Member {
    public:
    Member() = delete;
    Member(std::string tag, std::string fullName): tag(tag), fullName(fullName) {
        isHR = tag[0] == 'H' || tag[0] == 'h';
    }

    private:
    std::string tag;
    std::string fullName;

    bool isHR;

    public:

    std::string getTag() const {
        return tag;
    }

    std::string getFullName() const {
        return fullName;
    }

    bool getIsHR() const {
        return isHR;
    }

    public:

    bool operator<(const Member& other) const {
        return fullName < other.fullName;
    }
};

class MemberManager {
    private:
    MemberManager() = delete;
    ~MemberManager() = delete;
    MemberManager(const MemberManager&) = delete;
    MemberManager& operator=(const MemberManager&) = delete;

    inline static std::vector<Member> members{};
    inline static std::vector<Member> hrMembers{};
    inline static std::map<Member, std::vector<Member>> hrAssignments{};

    public:
    static void addMember(std::string tag, std::string fullName) {
        std::cerr << "Adding member: " << tag << " " << fullName << std::endl;

        if(fullName.empty()) {
            return;
        }

        if(tag == "H" || tag == "h") {
            hrMembers.emplace_back(tag, fullName);
            return;
        }

        members.emplace_back(tag, fullName);
    }

    static std::vector<Member> getMembers() {
        return members;
    }

    static std::vector<Member> getHRMembers() {
        return hrMembers;
    }

    static void assignHRMembers() {
        size_t hrCount = hrMembers.size();
        size_t hrIndex = 0;


        for(const auto& m : members) {
            const auto& hrMember = hrMembers[hrIndex];
            hrAssignments[hrMember].push_back(m);

            hrIndex = (hrIndex + 1) % hrCount;
        }
    }

    static std::map<Member, std::vector<Member>> getHRAssignments() {
        return hrAssignments;
    }
};