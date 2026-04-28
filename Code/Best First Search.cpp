#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>
#include <functional>

using namespace std;

// Hàm t?m ki?m t?t nh?t - Best-First Search
void TimKiemTotNhat(int batDau, int dich,
                    const vector<vector<int> >& dsKe,
                    const vector<int>& danhGia,
                    const vector<string>& tenDinh) {
    int n = dsKe.size();
    vector<bool> dong(n, false), trongMo(n, false);
    vector<int> cha(n, -1);

    typedef pair<int,int> Cap; // (f, ð?nh)
    priority_queue< Cap, vector<Cap>, greater<Cap> > MO;

    MO.push(Cap(danhGia[batDau], batDau));
    trongMo[batDau] = true;

    cout << "Khoi tao MO = { " << tenDinh[batDau] << "(f=" << danhGia[batDau] << ") }\n\n";

    while (!MO.empty()) {
        Cap hienTai = MO.top(); MO.pop();
        int u = hienTai.second;
        int fu = hienTai.first;
        trongMo[u] = false;

        if (dong[u]) continue;

        cout << "Lay dinh u = " << tenDinh[u] << "(f=" << fu << ") ra khoi MO\n";

        if (u == dich) {
            cout << "=> Tim thay dich: " << tenDinh[dich] << "\n";
            // D?ng l?i ðý?ng ði
            vector<int> duongDi;
            for (int x = u; x != -1; x = cha[x]) duongDi.push_back(x);
            cout << "Duong di: ";
            for (int i = duongDi.size()-1; i >= 0; --i) {
                cout << tenDinh[duongDi[i]];
                if (i) cout << " -> ";
            }
            cout << "\n";
            return;
        }

        dong[u] = true;

        cout << "Mo rong cac dinh ke cua " << tenDinh[u] << ": ";
        for (size_t i = 0; i < dsKe[u].size(); ++i) {
            int v = dsKe[u][i];
            cout << tenDinh[v] << "(f=" << danhGia[v] << ") ";
        }
        cout << "\n";

        for (size_t i = 0; i < dsKe[u].size(); ++i) {
            int v = dsKe[u][i];
            if (dong[v]) continue;
            if (!trongMo[v]) {
                cha[v] = u;
                MO.push(Cap(danhGia[v], v));
                trongMo[v] = true;
                cout << "  Chen " << tenDinh[v] << " vao MO (f=" << danhGia[v] << ")\n";
            } else {
                cout << "  " << tenDinh[v] << " da co trong MO, bo qua\n";
            }
        }

        // Hi?n th? MO hi?n t?i
        priority_queue< Cap, vector<Cap>, greater<Cap> > tam = MO;
        cout << "MO hien tai: { ";
        while (!tam.empty()) {
            Cap p = tam.top(); tam.pop();
            cout << tenDinh[p.second] << "(f=" << p.first << ")";
            if (!tam.empty()) cout << ", ";
        }
        cout << " }\n";

        cout << "DONG hien tai: { ";
        for (int i = 0; i < n; ++i) if (dong[i]) cout << tenDinh[i] << " ";
        cout << "}\n\n";
    }

    cout << "MO rong. Tim kiem that bai.\n";
}

int main() {
    // Ví d?: Ð? th? 5 ð?nh A,B,C,D,E
    int soDinh = 5;
    vector<vector<int> > dsKe(soDinh);
    // A=0,B=1,C=2,D=3,E=4
    dsKe[0].push_back(1); // A->B
    dsKe[0].push_back(2); // A->C
    dsKe[1].push_back(3); // B->D
    dsKe[2].push_back(3); // C->D
    dsKe[2].push_back(4); // C->E
    dsKe[3].push_back(4); // D->E

    vector<int> danhGia(soDinh);
    danhGia[0] = 10; // A
    danhGia[1] = 7;  // B
    danhGia[2] = 6;  // C
    danhGia[3] = 4;  // D
    danhGia[4] = 0;  // E (ðích)

    vector<string> tenDinh(soDinh);
    tenDinh[0] = "A"; tenDinh[1] = "B";
    tenDinh[2] = "C"; tenDinh[3] = "D"; tenDinh[4] = "E";

    int batDau = 0; // A
    int dich = 4;   // E

    // G?i hàm t?m ki?m v?i tên ti?ng Vi?t
    TimKiemTotNhat(batDau, dich, dsKe, danhGia, tenDinh);

    return 0;
}

