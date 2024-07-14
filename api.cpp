#include "api.h"
#include "into_json.h"
#include <string>
#include <vector>
#include "httplib.h"

using namespace std;
using httplib::Client;

// ����HTTP POST����
std::string new_trip(const Trip& new_t) {
    Client client("localhost", 3000);

    auto json_data = tripsToJson(new_t);
    httplib::Headers headers{
        { "Content-Type", "application/json" }
        //,{ "Content-Length", to_string(json_data.dump().length())}
        //,{ "a", "b"}
    };
    auto res = client.Post("/trip/", headers, json_data.dump(), "application/json");
    cout << json_data.dump();

    if (res && res->status == 200) {
        return string("Success");
    }
    else {
        //return "Error";
        return "Error: " + std::to_string(res ? res->status : -1);
    }
}

// ����HTTP DELETE����
std::string delete_trip(const Trip& target_t) {
    Client client("localhost", 3000);
    vector<Trip> vec = { target_t };

    auto json_data = tripsToJson(vec);
    auto res = client.Delete("/trip/", json_data.dump(), "application/json");

    if (res && res->status == 200) {
        return string("Success");
    }
    else {
        return "Error";
        //return "Error: " + std::to_string(res ? res->status : -1);
    }
}

// ����HTTP PUT����
std::string update_trip(const Trip& new_t) {
    Client client("localhost", 3000);
    vector<Trip> vec = { new_t };

    auto json_data = tripsToJson(vec);
    auto res = client.Put("/trip/", json_data.dump(), "application/json");

    if (res && res->status == 200) {
        return string("Success");
    }
    else {
        return "Error";
        //return "Error: " + std::to_string(res ? res->status : -1);
    }
}

vector<Trip> get_trip(vector<string> stfs, vector<string> arvs, vector<int> types) {
    string stf = stfs[0];
    string arv = arvs[0];
    int type = types[0];
    Client client("localhost", 3000);

    // ����query�ַ���
    std::string query;
    if (!stf.empty()) {
        query += "stfCity=" + stf;
    }
    if (!arv.empty()) {
        if (!query.empty()) query += "&";
        query += "arvCity=" + arv;
    }
    if (type != -1) {
        if (!query.empty()) query += "&";
        query += "type=" + std::to_string(type);
    }

    // ����GET����
    auto res = client.Get(("/trip/?" + query).c_str());

    // ������Ӧ
    
    std::vector<Trip> trips;
    /*
    if(res && res->status == 200) {
        auto j = nlohmann::json::parse(res->body);
        trips = jsonToTrips(j);
    }
    */
    if (res && res->status == 200) {
        try {
            auto j = nlohmann::json::parse(res->body);
            trips = jsonToTrips(j);
        }
        catch (const std::exception& e) {
            std::cerr << "JSON parsing error: " << e.what() << std::endl;
        }
    }
    else {
        std::cerr << "Error: " << (res ? res->status : -1) << std::endl;
    }
    
    return trips;
}

//**********************************************************

//**************************************************************************************

// ���� HTTP POST ���󴴽��µĳ���
string new_city(const City& new_t) {
    httplib::Client cli("localhost", 3000);
    nlohmann::json j = cityToJson(new_t);
    auto res = cli.Post("/city/", j.dump(), "application/json");
    if (res && res->status == 200) {
        return res->body;
    }
    else {
        return "Error: Failed to create new city.";
    }
}

// ���� HTTP DELETE ����ɾ��ָ���ĳ���
string delete_city(const City& target_t) {
    httplib::Client cli("localhost", 3000);
    nlohmann::json j = cityToJson(target_t);
    auto res = cli.Delete("/city/", j.dump(), "application/json");
    if (res && res->status == 200) {
        return res->body;
    }
    else {
        return "Error: Failed to delete city.";
    }
}

// ���� HTTP GET �����ȡ���г����б�
vector<City> get_city() {
    httplib::Client cli("localhost", 3000);
    auto res = cli.Get("/city/");
    vector<City> cities;
    if (res && res->status == 200) {
        nlohmann::json j = nlohmann::json::parse(res->body);
        for (const auto& element : j) {
            cities.push_back(jsonToCity(element));
        }
    }
    return cities;
}

// ���� HTTP PUT ������³�����Ϣ
string update_city(const City& new_t) {
    httplib::Client cli("localhost", 3000);
    nlohmann::json j = cityToJson(new_t);
    auto res = cli.Put("/city/", j.dump(), "application/json");
    if (res && res->status == 200) {
        return res->body;
    }
    else {
        return "Error: Failed to update city.";
    }
}
