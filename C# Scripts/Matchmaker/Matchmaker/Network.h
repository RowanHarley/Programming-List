#pragma once

class Network {
	public:
		enum Status {
			Available,
			StatusUnknown,
			CurrentlyDown
		};
		
		void Connect(char host, int port) {
			m_port = port;
			m_host = host;
		}
		void Connect() {

		}
		void Connect(char host, int port) {
			
		}
		void SetServerStatus(Status status) {
			
		}

	protected:
		Status m_status;
		int m_port;
		char m_host;
		class addr {
			addr() {
				return Exc
			}
		};
};
