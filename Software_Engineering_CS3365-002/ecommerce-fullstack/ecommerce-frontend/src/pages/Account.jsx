import React, { useState } from 'react';

export default function Account() {
  const [activeTab, setActiveTab] = useState('profile');
  const [user, setUser] = useState({
    name: 'Jacob Wallace',
    email: 'jacob@example.com',
    password: '',
    paymentMethod: 'Visa ending in 1234',
  });

  const [editing, setEditing] = useState(false);

  const handleChange = (e) => {
    const { name, value } = e.target;
    setUser(prev => ({ ...prev, [name]: value }));
  };

  const handleSave = () => {
    setEditing(false);
  };

  return (
    <div className="container" style={{ display: 'flex', gap: '2rem' }}>
      <aside style={{ minWidth: '200px' }}>
        <ul style={{ listStyle: 'none', padding: 0 }}>
          {['profile', 'payment', 'settings', 'danger'].map(tab => (
            <li key={tab} style={{ marginBottom: '1rem' }}>
              <button
                onClick={() => setActiveTab(tab)}
                style={{
                  width: '100%',
                  padding: '0.75rem 1rem',
                  textAlign: 'left',
                  backgroundColor: activeTab === tab ? '#2f80ed' : '#f2f2f2',
                  color: activeTab === tab ? '#fff' : '#333',
                  border: 'none',
                  borderRadius: '6px',
                  fontWeight: '500',
                  cursor: 'pointer'
                }}
              >
                {tab === 'profile' && 'Profile Info'}
                {tab === 'payment' && 'Payment Method'}
                {tab === 'settings' && 'Settings'}
                {tab === 'danger' && 'Danger Zone'}
              </button>
            </li>
          ))}
        </ul>
      </aside>

      <div style={{ flex: 1 }}>
        {activeTab === 'profile' && (
          <section>
            <h3>Profile Info</h3>
            {editing ? (
              <>
                <label>
                  Name: <br />
                  <input
                    type="text"
                    name="name"
                    value={user.name}
                    onChange={handleChange}
                    style={{ padding: '0.5rem', marginBottom: '1rem', width: '100%' }}
                  />
                </label>
                <br />
                <label>
                  Email: <br />
                  <input
                    type="email"
                    name="email"
                    value={user.email}
                    onChange={handleChange}
                    style={{ padding: '0.5rem', marginBottom: '1rem', width: '100%' }}
                  />
                </label>
                <br />
                <label>
                  Password: <br />
                  <input
                    type="password"
                    name="password"
                    value={user.password}
                    onChange={handleChange}
                    placeholder="••••••••••••"
                    style={{ padding: '0.5rem', marginBottom: '1rem', width: '100%' }}
                  />
                </label>
                <br />
                <button onClick={handleSave} style={{ marginRight: '1rem' }}>Save</button>
                <button onClick={() => setEditing(false)}>Cancel</button>
              </>
            ) : (
              <>
                <p><strong>Name:</strong> {user.name}</p>
                <p><strong>Email:</strong> {user.email}</p>
                <p><strong>Password:</strong> ••••••••••••</p>
                <button onClick={() => setEditing(true)}>Edit Info</button>
              </>
            )}
          </section>
        )}

        {activeTab === 'payment' && (
          <section>
            <h3>Payment Method</h3>
            <p>{user.paymentMethod}</p>
            <button>Update Payment Method</button>
          </section>
        )}

        {activeTab === 'settings' && (
          <section>
            <h3>Settings</h3>

            <div style={{ marginBottom: '1.5rem' }}>
              <h4>Email Notifications</h4>
              <label style={{ display: 'block', marginBottom: '0.5rem' }}>
                <input type="checkbox" defaultChecked /> Order Confirmations
              </label>
              <label style={{ display: 'block', marginBottom: '0.5rem' }}>
                <input type="checkbox" /> Shipping Updates
              </label>
              <label style={{ display: 'block', marginBottom: '0.5rem' }}>
                <input type="checkbox" /> Promotions & Offers
              </label>
            </div>

            <div style={{ marginBottom: '1.5rem' }}>
              <h4>Theme</h4>
              <select style={{ padding: '0.5rem', width: '100%', maxWidth: '300px' }}>
                <option>Light</option>
                <option>Dark</option>
                <option>System Default</option>
              </select>
            </div>

            <div style={{ marginBottom: '1.5rem' }}>
              <h4>Language</h4>
              <select style={{ padding: '0.5rem', width: '100%', maxWidth: '300px' }}>
                <option>English</option>
                <option>Spanish</option>
                <option>French</option>
              </select>
            </div>

            <button
              style={{
                padding: '0.6rem 1.25rem',
                backgroundColor: '#2f80ed',
                color: 'white',
                border: 'none',
                borderRadius: '6px',
                fontWeight: 'bold',
                cursor: 'pointer',
              }}
              onClick={() => alert('Settings saved! (mock)')}
            >
              Save Settings
            </button>
          </section>
        )}
        
        {activeTab === 'danger' && (
          <section style={{ borderTop: '1px solid #ccc', paddingTop: '1rem' }}>
            <h3 style={{ color: '#c0392b' }}>Danger Zone</h3>
            <button
              onClick={() => {
                if (window.confirm('Are you sure you want to delete your account? This cannot be undone.')) {
                  alert('Account deleted'); //maybe use a custom message later
                }
              }}
              style={{
                backgroundColor: '#e74c3c',
                color: 'white',
                padding: '0.5rem 1rem',
                border: 'none',
                borderRadius: '6px',
                cursor: 'pointer',
              }}
            >
              Delete Account
            </button>
          </section>
        )}
      </div>
    </div>

    
  );
}