import React from 'react';
import { useCart } from '../context/CartContext';
 
export default function Cart() {
  const { cartItems, dispatch } = useCart();
  
  const subtotal = cartItems.reduce((sum, item) => sum + item.price * item.quantity, 0);
  const tax = subtotal * 0.08;
  const total = subtotal + tax; 
  
  return (
    <div className="container" style={{ display: 'flex', flexDirection: 'row', gap: '2rem' }}>

      <div style={{ flex: 1 }}>
        <h2>Your Shopping Cart</h2>

        {cartItems.length === 0 ? (
          <p>Your cart is empty.</p> 
        ) : (
          <ul>
            {cartItems.map(item => (
              <li key={item.id} className="cart-item" style={{ display: 'flex', alignItems: 'center', gap: '1rem', marginBottom: '1rem' }}>
                <img
                  src={item.image} 
                  alt={item.name}
                  style={{ width: '60px', height: 'auto', objectFit: 'contain', borderRadius: '6px', backgroundColor: '#f0f0f0' }}
                />
                <div style={{ flex: 1 }}>
                  <strong>{item.name}</strong><br />
                  ${item.price.toLocaleString(undefined, { minimumFractionDigits: 2 })} × {item.quantity}
                </div> 
                <button
                  onClick={() => dispatch({ type: 'REMOVE_FROM_CART', payload: item.id })}
                  style={{ backgroundColor: '#e74c3c', color: 'white', border: 'none', padding: '0.3rem 0.7rem', borderRadius: '6px' }}
                >
                  Remove
                </button>
              </li>
            ))}
          </ul>
        )}
      </div>

      {cartItems.length > 0 && (
        <div style={{ flex: 1, border: '1px solid #ddd', padding: '1.5rem', borderRadius: '8px' }}>
          <h3>Checkout</h3>
        
          <div style={{ marginBottom: '1rem' }}>
            <p><strong>Subtotal:</strong> ${subtotal.toLocaleString(undefined, { minimumFractionDigits: 2 })}</p>
            <p><strong>Tax (8%):</strong> ${tax.toLocaleString(undefined, { minimumFractionDigits: 2 })}</p>
            <p><strong>Total:</strong> ${total.toLocaleString(undefined, { minimumFractionDigits: 2 })}</p>
          </div>

          <form onSubmit={(e) => {
            e.preventDefault();
            //alert('Order placed!');
          }}> 
            <label>
              Full Name: <br />
              <input type="text" required style={{ width: '100%', padding: '0.5rem', marginBottom: '1rem' }} />
            </label>
            <br /> 
            <label>
              Shipping Address: <br /> 
              <textarea required style={{ width: '100%', padding: '0.5rem', marginBottom: '1rem' }} />
            </label>
            <br />
            <label>
              Card Number: <br /> 
              <input type="text" placeholder="1234 5678 9012 3456" required style={{ width: '100%', padding: '0.5rem', marginBottom: '1rem' }} />
            </label>
            <br />
            <button
              type="submit"
              style={{
                backgroundColor: '#2f80ed', 
                color: 'white', 
                padding: '0.75rem 1.5rem',
                border: 'none', 
                borderRadius: '6px',
                fontSize: '1rem',
                cursor: 'pointer',
              }}
            > 
              Place Order
            </button>
          </form> 
        </div> 
      )}
    </div> 


  );
}