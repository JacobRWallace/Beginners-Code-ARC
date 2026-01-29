import React from 'react';
import { Link, useLocation } from 'react-router-dom';
import logo from '../assets/logo.png';

export default function Navbar() {
  const location = useLocation();

  return (
    <nav
      style={{
        padding: '1rem 2rem',
        backgroundColor: '#ffffff',
        borderBottom: '1px solid #ddd',
        display: 'flex',
        justifyContent: 'space-between',
        alignItems: 'center',
        boxShadow: '0 2px 4px rgba(0, 0, 0, 0.04)',
        position: 'sticky',
        top: 0,
        zIndex: 1000,
      }}
    >
      <Link to="/">
        <img
          src={logo}
          alt="Everything Store"
          style={{ height: '55px', objectFit: 'contain' }}
        />
      </Link>
      <div style={{ display: 'flex', gap: '1.5rem' }}>
        <NavLink to="/" current={location.pathname === '/'}>Home</NavLink>
        <NavLink to="/cart" current={location.pathname === '/cart'}>Cart</NavLink>
        <NavLink to="/account" current={location.pathname === '/account'}>Account</NavLink>
      </div>
    </nav>
  );
}

function NavLink({ to, children, current }) {
  return (
    <Link
      to={to}
      style={{
        position: 'relative',
        textDecoration: 'none',
        color: current ? '#2f80ed' : '#333',
        fontWeight: current ? '600' : '500',
        paddingBottom: '4px',
        transition: 'color 0.2s', 
        borderBottom: current ? '2px solid #2f80ed' : '2px solid transparent',
      }}
    >
      {children}
    </Link>
  );
}